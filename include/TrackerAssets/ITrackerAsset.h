// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
class TrackerEvent;

class ITrackerAsset {
 public:
  virtual bool accept(TrackerEvent* event) = 0;
  ITrackerAsset() = default;
  virtual ~ITrackerAsset() = default;
};
