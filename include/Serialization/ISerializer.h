// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

class TrackerEvent;

class ISerializer {
 public:
  virtual std::string serialize(TrackerEvent* event) noexcept = 0;
  virtual std::string getExtension() = 0;
  ISerializer() = default;
  virtual ~ISerializer() = default;
};
