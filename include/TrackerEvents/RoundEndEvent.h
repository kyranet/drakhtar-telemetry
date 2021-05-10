// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "EndEvent.h"

class RoundEndEvent : public EndEvent {
  uint32_t roundNumber_;

 public:
  RoundEndEvent();
  ~RoundEndEvent() override = default;
  void setRoundNumber(uint32_t roundNumber);
  void toJson(JsonObject& object) override;
};
