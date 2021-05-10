// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <sstream>
#include <string>
#include <vector>

#include "Serialization/IValueObject.h"
#include "Serialization/Padding.h"

class XmlObject : public IValueObject {
 protected:
  bool addedFirstElement_{false};
  std::stringstream stream_{};
  Padding padding_{};

  static constexpr char SPACE = ' ';
  static constexpr char NEW_LINE = '\n';

 public:
  XmlObject() = default;
  XmlObject(const std::string& padding) : padding_(padding) {}
  XmlObject(size_t padding) : padding_(padding) {}
  ~XmlObject() = default;

  void addPair(const std::string& key, const std::string& value) {
    addedFirstElement_ = true;

    stream_ << NEW_LINE << padding_.inner << '<' << key << '>' << value << "</"
            << key << '>';
  }

  void open();
  void close();

  void clear() noexcept;
  std::string toString() const noexcept;
};
