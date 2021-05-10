// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once

#include <ctime>
#include <string>

class JsonObject;
class XmlObject;

enum TrackerEventType {
  SESSION_START,
  SESSION_END,
  LEVEL_START,
  LEVEL_END,
  ROUND_START,
  ROUND_END,
  PLAYER_TURN_START,
  PLAYER_TURN_END,
  PAUSE_START,
  PAUSE_END,
  UNITS_PURCHASED,
  ATTACK
};

class TrackerEvent {
  time_t timestamp_;

 protected:
  TrackerEvent(TrackerEventType type);

 public:
  virtual ~TrackerEvent() = default;

  const TrackerEventType eventType_;
  const std::string idGame_;
  const std::string idSession_;

  time_t getTimeStamp() const { return timestamp_; };

  virtual void toJson(JsonObject& object);
  virtual void toXml(XmlObject& object);
};
