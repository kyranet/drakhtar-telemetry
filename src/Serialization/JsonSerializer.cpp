// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/JsonSerializer.h"

#include "TrackerEvents/TrackerEvent.h"
#include "Utils/JsonObject.h"

std::string JsonSerializer::serialize(TrackerEvent* event) noexcept {
  JsonObject object{2};
  event->toJson(object);
  return object.toString();
}
