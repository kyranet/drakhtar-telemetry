// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/TrackerEvent.h"

#include <ctime>

#include "Tracker.h"

TrackerEvent::TrackerEvent(TrackerEventType type)
    : eventType_(type), idSession_(Tracker::getInstance().getIdSession()) {
  std::time(&timestamp_);
}

std::string TrackerEvent::toJson() {
  std::string str = R"(      "IdSession": ")" + idSession_ + "\",\n";
  char time[30];
  std::strftime(time, 30, "%c", std::localtime(&timestamp_));
  str += R"(      "Time": ")" + std::string(time) + "\"";
  return str;
}
