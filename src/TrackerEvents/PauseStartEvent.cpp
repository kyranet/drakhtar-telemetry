// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PauseStartEvent.h"

#include "Serialization/Json/JsonObject.h"

PauseStartEvent::PauseStartEvent(uint32_t levelNumber)
    : TrackerEvent(PAUSE_START), levelNumber_(levelNumber) {}

void PauseStartEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Pause Start Event");
  TrackerEvent::toJson(object);
  object.add("Level", levelNumber_);
}
