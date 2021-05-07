// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/IValueStream.h"
#include "Serialization/Json/JsonObject.h"

class JsonArrayStream : private JsonObject, public IValueStream {
 public:
  JsonArrayStream() = default;
  JsonArrayStream(const std::string& padding) : JsonObject(padding) {}
  JsonArrayStream(size_t padding) : JsonObject(std::string(' ', padding)) {}
  ~JsonArrayStream() = default;

  void add(const std::string& value) override {
    if (!addedFirstElement_) {
      addedFirstElement_ = true;
    } else {
      stream_ << COMMA;
    }

    stream_ << NEW_LINE << padding_.inner << value;
  }

  void open() override { stream_ << START_ARRAY; }
  void close() override {
    if (addedFirstElement_) {
      stream_ << NEW_LINE << padding_.outter << END_ARRAY;
    } else {
      stream_ << END_ARRAY;
    }
  }

  void clear() noexcept override { JsonObject::clear(); }
  std::string toString() const noexcept override {
    return JsonObject::toString();
  }
};
