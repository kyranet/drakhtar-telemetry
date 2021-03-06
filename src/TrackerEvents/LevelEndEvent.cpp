// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/LevelEndEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

LevelEndEvent::LevelEndEvent(uint32_t levelNumber, LevelResult result,
                             std::map<std::string, uint16_t>* army)
    : EndEvent(LEVEL_END),
      levelNumber_(levelNumber),
      result_(result),
      army_(army) {}

std::string resultToString(LevelResult result) {
  switch (result) {
    case VICTORY:
      return "VICTORY";
    case DEFEAT:
      return "DEFEAT";
    case QUIT:
      return "QUIT";
    case RESTART:
      return "RESTART";
    case ERROR:
    default:
      return "ERROR";
  }
}

void LevelEndEvent::toJson(JsonObject& object) {
  object.add("EventType", "Level End Event");
  EndEvent::toJson(object);
  object.add("Level", levelNumber_);
  object.add("Result", resultToString(result_));

  for (auto& pair : *army_) {
    object.add(pair.first, pair.second);
  }
}

void LevelEndEvent::toXml(XmlObject& object) {
  object.add("EventType", "Level End Event");
  EndEvent::toXml(object);
  object.add("Level", levelNumber_);
  object.add("Result", resultToString(result_));

  for (auto& pair : *army_) {
    object.add(pair.first, pair.second);
  }
}
