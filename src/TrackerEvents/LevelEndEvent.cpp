// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/LevelEndEvent.h"

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
    case ERROR:
    default:
      return "ERROR";
  }
}

std::string LevelEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Level End Event",)";
  str += "\n" + EndEvent::toJson() + +",\n";
  str += R"(      "Level#": )" + std::to_string(levelNumber_) + ",\n";
  str += R"(      "Result": ")" + resultToString(result_) + "\"\n";

  std::map<std::string, uint16_t>::iterator it;
  str += "    (      \"Army#\": )\n";
  for (it = army_->begin(); it != army_->end(); it++) {
    str +=
        "            " + it->first + ": " + std::to_string(it->second) + "\n";
  }

  str += "    }";
  return str;
}
