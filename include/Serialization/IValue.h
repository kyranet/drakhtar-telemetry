// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

class IValue {
 protected:
  [[nodiscard]] virtual std::string formatString(
      const std::string& value) noexcept {
    return value;
  }

  [[nodiscard]] inline std::string serialize(
      const std::string& value) noexcept {
    return formatString(value);
  }

  [[nodiscard]] inline std::string serialize(const char* value) noexcept {
    return formatString(std::string(value));
  }

  [[nodiscard]] inline std::string serialize(const int8_t value) noexcept {
    return serialize(static_cast<int32_t>(value));
  }

  [[nodiscard]] inline std::string serialize(const uint8_t value) noexcept {
    return serialize(static_cast<uint32_t>(value));
  }

  [[nodiscard]] inline std::string serialize(const int16_t value) noexcept {
    return serialize(static_cast<int32_t>(value));
  }

  [[nodiscard]] inline std::string serialize(const uint16_t value) noexcept {
    return serialize(static_cast<uint32_t>(value));
  }

  [[nodiscard]] inline std::string serialize(const int32_t value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const uint32_t value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const int64_t value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const uint64_t value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const float value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const double value) noexcept {
    return std::to_string(value);
  }

  [[nodiscard]] inline std::string serialize(const bool value) noexcept {
    return value ? "true" : "false";
  }

  [[nodiscard]] inline std::string serialize(const IValue& value) noexcept {
    return value.toString();
  }

 public:
  virtual std::string toString() const noexcept = 0;
};
