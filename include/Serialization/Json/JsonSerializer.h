// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "Serialization/ISerializer.h"

class JsonSerializer : public ISerializer {
 public:
  std::string serialize(TrackerEvent* event) noexcept override;
  std::string getExtension() override { return ".json"; };
  JsonSerializer() = default;
  ~JsonSerializer() = default;
};
