// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/TrackerEvent.h"

#include <ctime>

#include "Tracker.h"
#include "Utils/JsonObject.h"

TrackerEvent::TrackerEvent(TrackerEventType type)
    : eventType_(type),
      idGame_(Tracker::getInstance().getIdGame()),
      idSession_(Tracker::getInstance().getIdSession()) {
  std::time(&timestamp_);
}

void TrackerEvent::toJson(JsonObject& object) {
  object.add("IdGame", idGame_);
  object.add("IdSession", idSession_);
  char time[30];
  std::strftime(time, 30, "%c", std::localtime(&timestamp_));
  object.add("Time", time);
}
