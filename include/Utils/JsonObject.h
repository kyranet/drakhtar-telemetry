// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include <sstream>
#include <string>
#include <vector>

#include "Utils/IValue.h"

class JsonObject : public IValue {
 protected:
  struct Padding {
    std::string outter{};
    std::string inner{};

    Padding() : outter(""), inner("  ") {}
    Padding(size_t padding)
        : outter(std::string(padding, ' ')),
          inner(std::string(padding + 2, ' ')) {}
    Padding(std::string padding) : outter(padding), inner(padding + "  ") {}
  };

  bool addedFirstElement_{false};
  std::stringstream stream_{};
  Padding padding_{};

 public:
  JsonObject() = default;
  JsonObject(const std::string& padding) : padding_(padding) {}
  JsonObject(size_t padding) : padding_(padding) {}
  ~JsonObject() = default;

  template <typename TKey, typename TValue>
  void add(const TKey& key, const TValue& value) {
    if (!addedFirstElement_) {
      addedFirstElement_ = true;
      stream_ << COMMA;
    }

    stream_ << NEW_LINE << padding_.inner << serialize(key) << COLON << SPACE
            << serialize(value);
  }

  inline void open() { stream_ << START_OBJECT; }
  inline void close() {
    if (addedFirstElement_) {
      stream_ << NEW_LINE << padding_.outter << END_OBJECT;
    } else {
      stream_ << END_OBJECT;
    }
  }

  inline void clear() { stream_.clear(); }
  inline std::string toString() const noexcept { return stream_.str(); }
};
