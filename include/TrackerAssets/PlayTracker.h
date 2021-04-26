#pragma once
#include <cstdint>
#include <ctime>

#include "ITrackerAsset.h"

class PlayTracker final : public ITrackerAsset {
  uint32_t roundCount_ = 0;
  time_t startRoundTime_ = 0;
  time_t startPlayerTurnTime_ = 0;
  time_t startLevelTime_ = 0;

 public:
  PlayTracker() = default;
  ~PlayTracker() = default;

  bool accept(TrackerEvent* event) override;
};
