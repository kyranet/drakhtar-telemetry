// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Serialization/Xml/XmlSerializer.h"

#include "Serialization/Xml/XmlObject.h"
#include "TrackerEvents/TrackerEvent.h"

std::string XmlSerializer::serialize(TrackerEvent* event) noexcept {
  XmlObject object{2};
  object.open();
  event->toXml(object);
  object.close();
  return object.toString();
}
