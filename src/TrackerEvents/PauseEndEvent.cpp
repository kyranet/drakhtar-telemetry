// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PauseEndEvent.h"

PauseEndEvent::PauseEndEvent(uint32_t levelNumber)
    : TrackerEvent(PAUSE_END), levelNumber_(levelNumber) {}

std::string PauseEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Pause End Event",)";
  str += "\n" + TrackerEvent::toJson() + +",\n";
  str += R"(      "Level#": )" + std::to_string(levelNumber_) + "\n";
  str += "    }";
  return str;
}
