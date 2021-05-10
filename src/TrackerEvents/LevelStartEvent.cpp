// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/LevelStartEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

LevelStartEvent::LevelStartEvent(uint32_t levelNumber,
                                 std::map<std::string, uint16_t>* army)
    : TrackerEvent(LEVEL_START), levelNumber_(levelNumber), army_(army) {}

void LevelStartEvent::toJson(JsonObject& object) {
  object.add("EventType", "Level Start Event");
  TrackerEvent::toJson(object);
  object.add("Level", levelNumber_);

  for (const auto& pair : *army_) {
    object.add(pair.first, pair.second);
  }
}

void LevelStartEvent::toXml(XmlObject& object) {
  object.add("EventType", "Level Start Event");
  TrackerEvent::toXml(object);
  object.add("Level", levelNumber_);

  for (const auto& pair : *army_) {
    object.add(pair.first, pair.second);
  }
}
