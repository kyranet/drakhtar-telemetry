// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <sstream>
#include <string>
#include <vector>

#include "Serialization/Padding.h"
#include "Serialization/Xml/IXmlValue.h"

class XmlObject : public IXmlValue {
 protected:
  bool addedFirstElement_{false};
  std::stringstream stream_{};
  Padding padding_{};

 public:
  XmlObject() = default;
  XmlObject(const std::string& padding) : padding_(padding) {}
  XmlObject(size_t padding) : padding_(padding) {}
  ~XmlObject() = default;

  template <typename TKey, typename TValue>
  void add(const TKey& key, const TValue& value) {
    addedFirstElement_ = true;

    const auto skey = serialize(key);
    stream_ << NEW_LINE << padding_.inner << '<' << skey << '>'
            << serialize(value) << "</" << skey << '>';
  }

  void open();
  void close();

  void clear() noexcept;
  std::string toString() const noexcept;
};
