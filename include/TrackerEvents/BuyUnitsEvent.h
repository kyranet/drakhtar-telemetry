// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <vector>

#include "TrackerEvent.h"

class BuyUnitsEvent : public TrackerEvent {
  std::string name_;
  uint16_t cost_;
  uint16_t amount_;

 public:
  BuyUnitsEvent(std::string name, uint16_t cost, uint16_t amount);
  ~BuyUnitsEvent() override = default;
  void toJson(JsonObject& object) override;
};
