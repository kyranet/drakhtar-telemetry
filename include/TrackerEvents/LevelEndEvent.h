// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <map>

#include "EndEvent.h"

enum LevelResult { VICTORY, DEFEAT, QUIT, ERROR };

class LevelEndEvent : public EndEvent {
  uint32_t levelNumber_;
  LevelResult result_;
  std::map<std::string, uint16_t>* army_;

 public:
  LevelEndEvent(uint32_t levelNumber, LevelResult result,
                std::map<std::string, uint16_t>* army);
  ~LevelEndEvent() override = default;
  void toJson(JsonObject& object) override;
};
