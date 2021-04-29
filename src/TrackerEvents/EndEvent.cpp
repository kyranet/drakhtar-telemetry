// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/EndEvent.h"

EndEvent::EndEvent(TrackerEventType type) : TrackerEvent(type) {}

std::string EndEvent::toJson() {
  std::string str = TrackerEvent::toJson() + +",\n";
  return str;
}
