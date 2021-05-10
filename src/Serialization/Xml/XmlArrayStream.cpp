// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/Xml/XmlArrayStream.h"

void XmlArrayStream::add(const std::string& value) {
  addedFirstElement_ = true;
  stream_ << NEW_LINE << padding_.inner << value;
}

void XmlArrayStream::open() {
  stream_ << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << NEW_LINE
          << "<Data>";
}
void XmlArrayStream::close() {
  if (addedFirstElement_) {
    stream_ << NEW_LINE << padding_.outter << "</Data>";
  } else {
    stream_ << "</Data>";
  }
}

void XmlArrayStream::clear() noexcept { XmlObject::clear(); }
std::string XmlArrayStream::toString() const noexcept {
  return XmlObject::toString();
}
