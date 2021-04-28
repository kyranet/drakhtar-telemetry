// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PlayerTurnEndEvent.h"

PlayerTurnEndEvent::PlayerTurnEndEvent() : EndEvent(PLAYER_TURN_END) {}

std::string PlayerTurnEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Player Turn End Event",)";
  str += "\n" + EndEvent::toJson() + +"\n";
  str += "    }";
  return str;
}
