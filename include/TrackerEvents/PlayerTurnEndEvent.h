// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "EndEvent.h"

class PlayerTurnEndEvent : public EndEvent {
 public:
  PlayerTurnEndEvent();
  ~PlayerTurnEndEvent() override = default;
  void toJson(JsonObject& object) override;
};
