// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <sstream>
#include <string>
#include <vector>

#include "Serialization/IValueObject.h"
#include "Serialization/Padding.h"

class JsonObject : public IValueObject {
 protected:
  [[nodiscard]] inline std::string formatString(
      const std::string& value) noexcept override {
    // NOTE: Within the boundaries of this program, we are not
    // serializing special characters (\r, \n...) nor quotes ("), so
    // escaping them is unnecessary. However, if the need arised and we
    // need to serialize user input, then we must escape said characters.
    return QUOTE + value + QUOTE;
  }

  bool addedFirstElement_{false};
  std::stringstream stream_{};
  Padding padding_{};

  static constexpr char COLON = ':';
  static constexpr char QUOTE = '"';
  static constexpr char COMMA = ',';
  static constexpr char SPACE = ' ';
  static constexpr char NEW_LINE = '\n';
  static constexpr char START_OBJECT = '{';
  static constexpr char END_OBJECT = '}';
  static constexpr char START_ARRAY = '[';
  static constexpr char END_ARRAY = ']';

 public:
  JsonObject() = default;
  JsonObject(const std::string& padding) : padding_(padding) {}
  JsonObject(size_t padding) : padding_(padding) {}
  ~JsonObject() = default;

  void addPair(const std::string& key, const std::string& value) {
    if (!addedFirstElement_) {
      addedFirstElement_ = true;
    } else {
      stream_ << COMMA;
    }

    stream_ << NEW_LINE << padding_.inner << key << COLON << SPACE << value;
  }

  void open();
  void close();

  void clear() noexcept;
  std::string toString() const noexcept;
};
