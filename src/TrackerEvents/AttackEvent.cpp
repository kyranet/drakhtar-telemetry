// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/AttackEvent.h"

#include "Serialization/Json/JsonObject.h"

AttackEvent::AttackEvent(std::string atk, std::string def, uint32_t dam)
    : TrackerEvent(ATTACK), attacker_(atk), defender_(def), damage_(dam) {}

void AttackEvent::toJson(JsonObject& object) {
  object.add("Event Type", "AttackEvent");
  TrackerEvent::toJson(object);
  object.add("Attacker", attacker_);
  object.add("Defender", defender_);
  object.add("AmountDamage", damage_);
}
