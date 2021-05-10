// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PauseStartEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

PauseStartEvent::PauseStartEvent(uint32_t levelNumber)
    : TrackerEvent(PAUSE_START), levelNumber_(levelNumber) {}

void PauseStartEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Pause Start Event");
  TrackerEvent::toJson(object);
  object.add("Level", levelNumber_);
}

void PauseStartEvent::toXml(XmlObject& object) {
  object.add("EventType", "Pause Start Event");
  TrackerEvent::toXml(object);
  object.add("Level", levelNumber_);
}
