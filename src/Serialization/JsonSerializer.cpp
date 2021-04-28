// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/JsonSerializer.h"

#include "TrackerEvents/TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* event) noexcept {
  return event->toJson();
}
