// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/BuyUnitsEvent.h"

BuyUnitsEvent::BuyUnitsEvent(std::vector<UnitPurchase> unitsPurchased)
    : TrackerEvent(LEVEL_START), unitsPurchased_(unitsPurchased) {}

std::string BuyUnitsEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Buy Units Event",)";
  str += "\n" + TrackerEvent::toJson() + +",\n";

  str += "    (      \"Units purchased#\": )\n";
  for (int i = 0; i < unitsPurchased_.size(); i++) {
    str += "            " + std::to_string(unitsPurchased_[i].amount) + " " +
           unitsPurchased_[i].name + "s at " +
           std::to_string(unitsPurchased_[i].cost) + " each" + "\n";
  }

  str += "    }";
  return str;
}
