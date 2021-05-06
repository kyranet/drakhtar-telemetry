// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/SessionStartEvent.h"

#include "Utils/JsonObject.h"

SessionStartEvent::SessionStartEvent() : TrackerEvent(SESSION_START) {}

void SessionStartEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Session Start Event");
  TrackerEvent::toJson(object);
}
