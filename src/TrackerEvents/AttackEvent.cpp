// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/AttackEvent.h"

AttackEvent::AttackEvent(uint32_t atk, std::string def, std::string dam)
    : TrackerEvent(ARMY_HIT_POINT),
      attacker(atk),
      defender(def),
      damage_(dam) {}

std::string AttackEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "AttackEvent",)";
  str += "\n" + TrackerEvent::toJson() + ",\n";
  str += R"(      "Attacker#": )" + attacker_ + "\n";
  str += R"(      "Defender#": )" + defender_ + "\n";
  str += R"(      "AmountDamage#": )" + std::to_string(damage_) + "\n";
  str += "    }";
  return str;
}
