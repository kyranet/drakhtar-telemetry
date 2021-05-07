// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include <string>

class IValue {
 public:
  virtual std::string toString() const noexcept = 0;
};
