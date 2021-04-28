// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PlayerTurnStartEvent.h"

PlayerTurnStartEvent::PlayerTurnStartEvent()
    : TrackerEvent(PLAYER_TURN_START) {}

std::string PlayerTurnStartEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Player Turn Start Event",)";
  str += "\n" + TrackerEvent::toJson() + +"\n";
  str += "    }";
  return str;
}
