// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "Serialization/IValueStream.h"
#include "Serialization/Xml/XmlObject.h"

class XmlArrayStream : private XmlObject, public IValueStream {
 public:
  XmlArrayStream() = default;
  XmlArrayStream(const std::string& padding) : XmlObject(padding) {}
  XmlArrayStream(size_t padding) : XmlObject(padding) {}
  ~XmlArrayStream() = default;

  void add(const std::string& value) override;

  void open() override;
  void close() override;

  void clear() noexcept override;
  std::string toString() const noexcept override;
};
