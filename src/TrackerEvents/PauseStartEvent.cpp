// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PauseStartEvent.h"

PauseStartEvent::PauseStartEvent(uint32_t levelNumber)
    : TrackerEvent(PAUSE_START), levelNumber_(levelNumber) {}

std::string PauseStartEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Pause Start Event",)";
  str += "\n" + TrackerEvent::toJson() + +",\n";
  str += R"(      "Level#": )" + std::to_string(levelNumber_) + "\n";
  str += "    }";
  return str;
}
