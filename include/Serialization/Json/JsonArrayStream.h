// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/IValueStream.h"
#include "Serialization/Json/JsonObject.h"

class JsonArrayStream : private JsonObject, public IValueStream {
 public:
  JsonArrayStream() = default;
  JsonArrayStream(const std::string& padding) : JsonObject(padding) {}
  JsonArrayStream(size_t padding) : JsonObject(padding) {}
  ~JsonArrayStream() = default;

  void add(const std::string& value) override;

  void open() override;
  void close() override;

  void clear() noexcept override;
  std::string toString() const noexcept override;
};
