// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/Json/JsonArrayStream.h"

void JsonArrayStream::add(const std::string& value) {
  if (!addedFirstElement_) {
    addedFirstElement_ = true;
  } else {
    stream_ << COMMA;
  }

  stream_ << NEW_LINE << padding_.inner << value;
}

void JsonArrayStream::open() { stream_ << START_ARRAY; }
void JsonArrayStream::close() {
  if (addedFirstElement_) {
    stream_ << NEW_LINE << padding_.outter << END_ARRAY;
  } else {
    stream_ << END_ARRAY;
  }
}

void JsonArrayStream::clear() noexcept { JsonObject::clear(); }
std::string JsonArrayStream::toString() const noexcept {
  return JsonObject::toString();
}
