// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <cstdint>
#include <ctime>

#include "ITrackerAsset.h"

class DrakhtarTracker final : public ITrackerAsset {
  uint32_t roundCount_ = 0;
  time_t startRoundTime_ = 0;
  time_t startPlayerTurnTime_ = 0;
  time_t startLevelTime_ = 0;

 public:
  DrakhtarTracker() = default;
  ~DrakhtarTracker() = default;

  bool accept(TrackerEvent* event) override;
};
