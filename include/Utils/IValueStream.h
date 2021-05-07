// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include <string>

class IValueStream {
 public:
  IValueStream() noexcept = default;
  virtual ~IValueStream() noexcept = default;

  virtual void add(const std::string& value) = 0;
  virtual std::string toString() const noexcept = 0;
  virtual void clear() noexcept = 0;
};
