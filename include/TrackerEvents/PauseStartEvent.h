// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class PauseStartEvent : public TrackerEvent {
  uint32_t levelNumber_;

 public:
  PauseStartEvent(uint32_t levelNumber);
  ~PauseStartEvent() override = default;
  std::string toJson() override;
};
