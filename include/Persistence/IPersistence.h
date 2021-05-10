// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <ctime>
#include <mutex>
#include <queue>
#include <thread>

class TrackerEvent;
class ISerializer;
class IValueStream;

class IPersistence {
 protected:
  IValueStream* stream_ = nullptr;
  ISerializer* serializer_ = nullptr;
  std::queue<TrackerEvent*> events{};
  IPersistence() = default;

 public:
  void setValueStream(IValueStream* stream);
  void setSerializer(ISerializer* serializer);

  virtual void send(TrackerEvent* event) = 0;
  virtual void flush() = 0;
  virtual ~IPersistence();
};
