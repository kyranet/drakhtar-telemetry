// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Persistence/IPersistence.h"

#include "Serialization/ISerializer.h"
#include "Serialization/IValueStream.h"
#include "TrackerEvents/TrackerEvent.h"

void IPersistence::setValueStream(IValueStream* stream) {
  stream_ = stream;
  stream_->open();
}

void IPersistence::setSerializer(ISerializer* serializer) {
  serializer_ = serializer;
}

IPersistence::~IPersistence() {
  delete stream_;
  delete serializer_;

  while (!events.empty()) {
    delete events.front();
    events.pop();
  }
}
