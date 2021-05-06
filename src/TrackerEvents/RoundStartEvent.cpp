// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/RoundStartEvent.h"

#include "Utils/JsonObject.h"

RoundStartEvent::RoundStartEvent() : TrackerEvent(ROUND_START) {}

void RoundStartEvent::setRoundNumber(uint32_t roundNumber) {
  roundNumber_ = roundNumber;
}

void RoundStartEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Round Start Event");
  TrackerEvent::toJson(object);
  object.add("Round", roundNumber_);
}
