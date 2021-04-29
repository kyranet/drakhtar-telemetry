// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"
#include <map>

class LevelStartEvent : public TrackerEvent {
  uint32_t levelNumber_;
  std::map<std::string, uint16_t>* army_;

 public:
  LevelStartEvent(uint32_t levelNumber, std::map<std::string, uint16_t>* army);
  ~LevelStartEvent() override = default;
  std::string toJson() override;
};
