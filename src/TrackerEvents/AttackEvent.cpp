// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/AttackEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

AttackEvent::AttackEvent(std::string atk, std::string def, uint32_t dam)
    : TrackerEvent(ATTACK), attacker_(atk), defender_(def), damage_(dam) {}

void AttackEvent::toJson(JsonObject& object) {
  object.add("EventType", "AttackEvent");
  TrackerEvent::toJson(object);
  object.add("Attacker", attacker_);
  object.add("Defender", defender_);
  object.add("AmountDamage", damage_);
}

void AttackEvent::toXml(XmlObject& object) {
  object.add("EventType", "AttackEvent");
  TrackerEvent::toXml(object);
  object.add("Attacker", attacker_);
  object.add("Defender", defender_);
  object.add("AmountDamage", damage_);
}
