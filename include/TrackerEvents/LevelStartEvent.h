// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <map>

#include "TrackerEvent.h"

class LevelStartEvent : public TrackerEvent {
  uint32_t levelNumber_;
  std::map<std::string, uint16_t>* army_;

 public:
  LevelStartEvent(uint32_t levelNumber, std::map<std::string, uint16_t>* army);
  ~LevelStartEvent() override = default;
  void toJson(JsonObject& object) override;
};
