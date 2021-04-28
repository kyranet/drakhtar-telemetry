// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class SessionStartEvent : public TrackerEvent {
 public:
  SessionStartEvent();
  ~SessionStartEvent() = default;
  std::string toJson() override;
};
