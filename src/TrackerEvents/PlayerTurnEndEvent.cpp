// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerEvents/PlayerTurnEndEvent.h"

#include "Serialization/Json/JsonObject.h"

PlayerTurnEndEvent::PlayerTurnEndEvent() : EndEvent(PLAYER_TURN_END) {}

void PlayerTurnEndEvent::toJson(JsonObject& object) {
  object.add("Event Type", "Player Turn End Event");
  EndEvent::toJson(object);
}
