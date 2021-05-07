// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Persistence/FilePersistence.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Serialization/ISerializer.h"
#include "Serialization/IValueStream.h"
#include "Tracker.h"
#include "TrackerEvents/TrackerEvent.h"

FilePersistence::FilePersistence(uint32_t timer) {
  timer_ = timer;
  std::ofstream file;
  startThread();
}

void FilePersistence::send(TrackerEvent* event) {
  std::lock_guard<std::mutex> lock(eventMutex_);
  events.push(event);
}

void FilePersistence::flush() {
  // If there are no events, return early:
  if (Tracker::isRunning() && events.empty()) return;

  std::ofstream file;
  try {
    // Read all the pending events:
    eventMutex_.lock();
    for (auto size = events.size(); size > 0; --size) {
      auto& event = events.front();
      events.pop();
      eventMutex_.unlock();
      stream_->add(serializer_->serialize(event));
      delete event;
      eventMutex_.lock();
    }
    eventMutex_.unlock();

    // If no file name was set, assign a new one:
    if (filename_.empty())
      filename_ = "data/" + Tracker::getInstance().getIdSession() +
                  serializer_->getExtension();

    // Open the file for writing:
    file.open(filename_, std::ofstream::out | std::ofstream::app);
    if (file.fail())
      throw std::runtime_error("Tracker Error data Folder is missing.");

    // If the tracker finished running, close the stream:
    if (!Tracker::isRunning()) stream_->close();

    // Write the stream contents into the file, then clear the stream
    // contents:
    file << stream_->toString();
    stream_->clear();

    file.close();
  } catch (std::exception&) {
    file.close();

    throw std::runtime_error("Tracker Error data Folder is missing.");
  }
}

void FilePersistence::run() {
  try {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    float previousFlushTime = std::clock();
    previousFlushTime /= CLOCKS_PER_SEC;
    while (Tracker::isRunning()) {
      float currentTime = std::clock();
      currentTime /= CLOCKS_PER_SEC;
      if (currentTime - previousFlushTime >= timer_) {
        flush();
        previousFlushTime = currentTime;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}

void FilePersistence::startThread() {
  flushThread_ = new std::thread([&]() { run(); });
}

FilePersistence::~FilePersistence() {
  flushThread_->join();
  delete flushThread_;
  try {
    flush();
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
