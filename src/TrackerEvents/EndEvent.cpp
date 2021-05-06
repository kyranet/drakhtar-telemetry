// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/EndEvent.h"

#include "Utils/JsonObject.h"

EndEvent::EndEvent(TrackerEventType type) : TrackerEvent(type) {}

void EndEvent::toJson(JsonObject& object) { TrackerEvent::toJson(object); }
