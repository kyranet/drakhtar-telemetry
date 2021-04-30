// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <vector>

#include "TrackerEvent.h"

class BuyUnitsEvent : public TrackerEvent {
  struct UnitPurchase {
    std::string name;
    uint16_t cost;
    uint16_t amount;
  };

  std::vector<UnitPurchase> unitsPurchased_;

 public:
  BuyUnitsEvent(std::vector<UnitPurchase> unitsPurchased);
  ~BuyUnitsEvent() override = default;
  std::string toJson() override;
};
