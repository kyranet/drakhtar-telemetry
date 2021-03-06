// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

class IValueStream {
 public:
  IValueStream() = default;
  virtual ~IValueStream() = default;

  virtual void add(const std::string& value) = 0;
  virtual std::string toString() const noexcept = 0;
  virtual void clear() noexcept = 0;

  virtual void open() = 0;
  virtual void close() = 0;
};
