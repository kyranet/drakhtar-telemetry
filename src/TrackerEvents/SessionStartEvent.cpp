// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/SessionStartEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

SessionStartEvent::SessionStartEvent() : TrackerEvent(SESSION_START) {}

void SessionStartEvent::toJson(JsonObject& object) {
  object.add("EventType", "Session Start Event");
  TrackerEvent::toJson(object);
}

void SessionStartEvent::toXml(XmlObject& object) {
  object.add("EventType", "Session Start Event");
  TrackerEvent::toXml(object);
}
