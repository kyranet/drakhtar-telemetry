// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/SessionEndEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

SessionEndEvent::SessionEndEvent() : EndEvent(SESSION_END) {}

void SessionEndEvent::toJson(JsonObject& object) {
  object.add("EventType", "Session End Event");
  EndEvent::toJson(object);
}

void SessionEndEvent::toXml(XmlObject& object) {
  object.add("EventType", "Session End Event");
  EndEvent::toXml(object);
}
