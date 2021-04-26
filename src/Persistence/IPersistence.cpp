#include "Persistence/IPersistence.h"

#include "Serialization/ISerializer.h"
#include "TrackerEvents/TrackerEvent.h"

void IPersistence::setSerializer(ISerializer* serializer) {
  serializer_ = serializer;
}

IPersistence::~IPersistence() {
  delete serializer_;

  while (!events.empty()) {
    delete events.front();
    events.pop();
  }
}
