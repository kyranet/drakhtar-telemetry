#include "Serialization/Json/JsonObject.h"

void JsonObject::open() { stream_ << START_OBJECT; }
void JsonObject::close() {
  if (addedFirstElement_) {
    stream_ << NEW_LINE << padding_.outter << END_OBJECT;
  } else {
    stream_ << END_OBJECT;
  }
}

void JsonObject::clear() noexcept { stream_.str(""); }
std::string JsonObject::toString() const noexcept { return stream_.str(); }
