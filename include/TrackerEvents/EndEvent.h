// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "TrackerEvent.h"

class EndEvent : public TrackerEvent {
 protected:
  EndEvent(TrackerEventType type);

 public:
  ~EndEvent() override = default;
  virtual void toJson(JsonObject& object) override;
};
