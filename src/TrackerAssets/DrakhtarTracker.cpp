// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "TrackerAssets/DrakhtarTracker.h"

#include "TrackerEvents/AttackEvent.h"
#include "TrackerEvents/BuyUnitsEvent.h"
#include "TrackerEvents/LevelEndEvent.h"
#include "TrackerEvents/LevelStartEvent.h"
#include "TrackerEvents/PauseEndEvent.h"
#include "TrackerEvents/PauseStartEvent.h"
#include "TrackerEvents/TrackerEvent.h"

bool DrakhtarTracker::accept(TrackerEvent* event) {
  time_t endTime;
  switch (event->eventType_) {
    case LEVEL_START:
      std::time(&startLevelTime_);
      roundCount_ = 0;
      return true;

    case LEVEL_END:
      std::time(&endTime);
      return true;

    case ATTACK:
      return true;

    case UNITS_PURCHASED:
      return true;

    case PAUSE_START:
      return true;

    case PAUSE_END:
      return true;

    case SESSION_START:
      return true;

    case SESSION_END:
      return true;

    default:
      return false;
  }
}
