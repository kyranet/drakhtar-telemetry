// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/Xml/XmlObject.h"

void XmlObject::open() { stream_ << "<Event>"; }
void XmlObject::close() {
  if (addedFirstElement_) {
    stream_ << NEW_LINE << padding_.outter << "</Event>";
  } else {
    stream_ << "</Event>";
  }
}

void XmlObject::clear() noexcept { stream_.str(""); }
std::string XmlObject::toString() const noexcept { return stream_.str(); }
