// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include "EndEvent.h"

class SessionEndEvent : public EndEvent {
 public:
  SessionEndEvent();
  ~SessionEndEvent() override = default;
  void toJson(JsonObject& object) override;
  void toXml(XmlObject& object) override;
};
