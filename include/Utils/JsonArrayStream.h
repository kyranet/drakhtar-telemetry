// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Utils/IValueStream.h"
#include "Utils/JsonObject.h"

class JsonArrayStream : private JsonObject, public IValueStream {
 public:
  JsonArrayStream() = default;
  JsonArrayStream(const std::string& padding) : JsonObject(padding) {}
  JsonArrayStream(size_t padding) : JsonObject(std::string(' ', padding)) {}
  ~JsonArrayStream() = default;

  void add(const std::string& value) {
    if (!addedFirstElement_) {
      addedFirstElement_ = true;
      stream_ << COMMA;
    }

    stream_ << NEW_LINE << padding_.inner << value;
  }

  inline void open() { stream_ << START_ARRAY; }
  inline void close() {
    if (addedFirstElement_) {
      stream_ << NEW_LINE << padding_.outter << END_ARRAY;
    } else {
      stream_ << END_ARRAY;
    }
  }

  void clear() noexcept { JsonObject::clear(); }
  std::string toString() const noexcept { return JsonObject::toString(); }
};
