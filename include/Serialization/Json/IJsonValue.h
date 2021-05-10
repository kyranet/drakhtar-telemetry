// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

#include "Serialization/IValue.h"

class IJsonValue : public IValue {
 protected:
  [[nodiscard]] inline static std::string serialize(
      const std::string& value) noexcept {
    // NOTE: Within the boundaries of this program, we are not
    // serializing special characters (\r, \n...) nor quotes ("), so
    // escaping them is unnecessary. However, if the need arised and we
    // need to serialize user input, then we must escape said characters.
    return QUOTE + value + QUOTE;
  }

  [[nodiscard]] inline static std::string serialize(
      const char* value) noexcept {
    return IValue::serialize(value);
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

  static constexpr char COLON = ':';
  static constexpr char QUOTE = '"';
  static constexpr char COMMA = ',';
  static constexpr char SPACE = ' ';
  static constexpr char NEW_LINE = '\n';
  static constexpr char START_OBJECT = '{';
  static constexpr char END_OBJECT = '}';
  static constexpr char START_ARRAY = '[';
  static constexpr char END_ARRAY = ']';
};
