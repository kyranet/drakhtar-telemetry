// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/SessionEndEvent.h"

#include "Utils/JsonObject.h"

SessionEndEvent::SessionEndEvent() : EndEvent(SESSION_END) {}

void SessionEndEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Session End Event");
  EndEvent::toJson(object);
}
