// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class RoundStartEvent : public TrackerEvent {
  uint32_t roundNumber_;

 public:
  RoundStartEvent();
  void setRoundNumber(uint32_t roundNumber);
  ~RoundStartEvent() override = default;
  void toJson(JsonObject& object) override;
};
