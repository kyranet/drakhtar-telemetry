#include "Serialization/JsonSerializer.h"

#include "TrackerEvents/TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* event) noexcept {
  return event->toJson();
}
