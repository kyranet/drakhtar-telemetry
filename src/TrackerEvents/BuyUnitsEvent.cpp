// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/BuyUnitsEvent.h"

#include "Serialization/Json/JsonObject.h"

BuyUnitsEvent::BuyUnitsEvent(std::string name, uint16_t cost, uint16_t amount)
    : TrackerEvent(UNITS_PURCHASED),
      name_(name),
      cost_(cost),
      amount_(amount) {}

void BuyUnitsEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Buy Units Event");
  TrackerEvent::toJson(object);
  object.add("UnitName", name_);
  object.add("UnitAmount", amount_);
  object.add("UnitCost", cost_);
}
