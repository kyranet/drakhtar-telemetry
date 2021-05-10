// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

#include "Serialization/IValue.h"

class IValueObject : public IValue {
 protected:
  virtual std::string serializeKey(const std::string& key) noexcept {
    return serialize(key);
  }

  virtual void addPair(const std::string& key, const std::string& value) = 0;

 public:
  virtual std::string toString() const noexcept = 0;

  template <typename TValue>
  inline void add(const char* key, const TValue& value) {
    add(std::string(key), value);
  }

  template <typename TValue>
  inline void add(const std::string& key, const TValue& value) {
    addPair(serializeKey(key), serialize(value));
  }
};
