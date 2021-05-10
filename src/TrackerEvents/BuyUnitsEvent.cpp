// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/BuyUnitsEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

BuyUnitsEvent::BuyUnitsEvent(std::string name, uint16_t cost, uint16_t amount)
    : TrackerEvent(UNITS_PURCHASED),
      name_(name),
      cost_(cost),
      amount_(amount) {}

void BuyUnitsEvent::toJson(JsonObject& object) {
  object.add("EventType", "Buy Units Event");
  TrackerEvent::toJson(object);
  object.add("UnitName", name_);
  object.add("UnitAmount", amount_);
  object.add("UnitCost", cost_);
}

void BuyUnitsEvent::toXml(XmlObject& object) {
  object.add("EventType", "Buy Units Event");
  TrackerEvent::toXml(object);
  object.add("UnitName", name_);
  object.add("UnitAmount", amount_);
  object.add("UnitCost", cost_);
}
