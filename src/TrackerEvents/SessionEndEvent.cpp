// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(uint32_t duration) : EndEvent(SESSION_END) {}

std::string SessionEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Session End Event",)";
  str += "\n" + EndEvent::toJson() + +"\n";
  str += "    }\n";
  str += "  ]\n";
  str += "}\n\n";
  return str;
}
