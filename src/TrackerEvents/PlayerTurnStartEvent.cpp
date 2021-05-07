// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PlayerTurnStartEvent.h"

#include "Serialization/Json/JsonObject.h"

PlayerTurnStartEvent::PlayerTurnStartEvent()
    : TrackerEvent(PLAYER_TURN_START) {}

void PlayerTurnStartEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Player Turn Start Event");
  TrackerEvent::toJson(object);
}
