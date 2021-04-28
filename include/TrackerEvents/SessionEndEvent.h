// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "EndEvent.h"

class SessionEndEvent : public EndEvent {
 public:
  SessionEndEvent(uint32_t duration);
  ~SessionEndEvent() override = default;
  std::string toJson() override;
};
