// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/BuyUnitsEvent.h"

BuyUnitsEvent::BuyUnitsEvent(std::string name, uint16_t cost, uint16_t amount)
    : TrackerEvent(UNITS_PURCHASED), name_(name), cost_(cost), amount_(amount) {}

std::string BuyUnitsEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Buy Units Event",)";
  str += "\n" + TrackerEvent::toJson() + +",\n";

  str += "    (      \"Purchased )\n";
    str += "            " + std::to_string(amount_) + " " +
           name_ + "s at " +
           std::to_string(cost_) + " gold each" + "\n";

  str += "    }";
  return str;
}
