// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/EndEvent.h"

#include "Serialization/Json/JsonObject.h"
#include "Serialization/Xml/XmlObject.h"

EndEvent::EndEvent(TrackerEventType type) : TrackerEvent(type) {}

void EndEvent::toJson(JsonObject& object) { TrackerEvent::toJson(object); }
void EndEvent::toXml(XmlObject& object) { TrackerEvent::toXml(object); }
