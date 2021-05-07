// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/RoundEndEvent.h"

#include "Serialization/Json/JsonObject.h"

RoundEndEvent::RoundEndEvent() : EndEvent(ROUND_END) {}

void RoundEndEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Round End Event");
  EndEvent::toJson(object);
  object.add("Round", roundNumber_);
}

void RoundEndEvent::setRoundNumber(uint32_t roundNumber) {
  roundNumber_ = roundNumber;
}
