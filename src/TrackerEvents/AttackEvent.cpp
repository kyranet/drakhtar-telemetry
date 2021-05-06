// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/AttackEvent.h"

AttackEvent::AttackEvent(std::string atk, std::string def, uint32_t dam)
    : TrackerEvent(ATTACK), attacker_(atk), defender_(def), damage_(dam) {}

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
