// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "Serialization/ISerializer.h"

class XmlSerializer : public ISerializer {
 public:
  std::string serialize(TrackerEvent* event) noexcept override;
  std::string getExtension() override { return ".xml"; };
  XmlSerializer() = default;
  ~XmlSerializer() = default;
};
