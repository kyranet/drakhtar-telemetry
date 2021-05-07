// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/Json/JsonSerializer.h"

#include "Serialization/Json/JsonObject.h"
#include "TrackerEvents/TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* event) noexcept {
  JsonObject object{2};
  object.open();
  event->toJson(object);
  object.close();
  return object.toString();
}
