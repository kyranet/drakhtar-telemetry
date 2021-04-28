// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class PlayerTurnStartEvent : public TrackerEvent {
 public:
  PlayerTurnStartEvent();
  ~PlayerTurnStartEvent() override = default;
  std::string toJson() override;
};
