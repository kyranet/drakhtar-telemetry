// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class PauseEndEvent : public TrackerEvent {
  uint32_t levelNumber_;

 public:
  PauseEndEvent(uint32_t levelNumber);
  ~PauseStartEvent() override = default;
  std::string toJson() override;
};
