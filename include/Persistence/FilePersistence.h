// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once

#include <string>

#include "IPersistence.h"

class FilePersistence final : public IPersistence {
  std::mutex eventMutex_;
  uint64_t timer_{60};
  std::thread* flushThread_;
  std::string filename_{""};

 public:
  FilePersistence(uint64_t timer);
  void send(TrackerEvent* event) override;
  void flush() override;
  void run();
  void startThread();
  ~FilePersistence();
};
