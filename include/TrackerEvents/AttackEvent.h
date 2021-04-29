// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class AttackEvent : public TrackerEvent {
  std::string attacker_;
  std::string denfender_;
  uint32_t damage_;

 public:
  AttackEvent(std::string atk, std::string def, uint32_t dam);
  ~AttackEvent() override = default;
  std::string toJson() override;
};
