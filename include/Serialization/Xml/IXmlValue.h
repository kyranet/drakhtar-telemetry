// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

#include "Serialization/IValue.h"

class IXmlValue : public IValue {
 protected:
  [[nodiscard]] inline static std::string serialize(
      const std::string& value) noexcept {
    return value;
  }

  [[nodiscard]] inline static std::string serialize(
      const char* value) noexcept {
    return serialize(std::string(value));
  }

  [[nodiscard]] inline static std::string serialize(
      const int8_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const uint8_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const int16_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const uint16_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const int32_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const uint32_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const int64_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const uint64_t value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const float value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const double value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(const bool value) noexcept {
    return IValue::serialize(value);
  }

  [[nodiscard]] inline static std::string serialize(
      const IValue& value) noexcept {
    return IValue::serialize(value);
  }

 public:
  virtual std::string toString() const noexcept = 0;

  static constexpr char SPACE = ' ';
  static constexpr char NEW_LINE = '\n';
};
