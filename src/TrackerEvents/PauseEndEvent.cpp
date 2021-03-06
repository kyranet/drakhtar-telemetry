// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PauseEndEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

PauseEndEvent::PauseEndEvent(uint32_t levelNumber)
    : TrackerEvent(PAUSE_END), levelNumber_(levelNumber) {}

void PauseEndEvent::toJson(JsonObject& object) {
  object.add("EventType", "Pause End Event");
  TrackerEvent::toJson(object);
  object.add("Level", levelNumber_);
}

void PauseEndEvent::toXml(XmlObject& object) {
  object.add("EventType", "Pause End Event");
  TrackerEvent::toXml(object);
  object.add("Level", levelNumber_);
}
