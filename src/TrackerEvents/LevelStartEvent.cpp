// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/LevelStartEvent.h"

LevelStartEvent::LevelStartEvent(uint32_t levelNumber,
                                 std::map<std::string, uint16_t>* army)
    : TrackerEvent(LEVEL_START), levelNumber_(levelNumber), army_(army) {}

std::string LevelStartEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Level Start Event",)";
  str += "\n" + TrackerEvent::toJson() + ",\n";
  str += R"(      "Level": )" + std::to_string(levelNumber_) + "\n";

  std::map<std::string, uint16_t>::iterator it;
  str += R"(      "Army":)";
  for (it = army_->begin(); it != army_->end(); it++) {
    str += "\n            " + it->first + ": " + std::to_string(it->second);
  }

  str += "\n    }";
  return str;
}
