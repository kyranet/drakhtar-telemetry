// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#include "Configuration.h"

#ifdef TELEMETRY

void TrackerConfiguration() {
  IValueStream* stream = nullptr;
  ISerializer* serializer = nullptr;
  IPersistence* persistence = nullptr;

#ifdef FILE_PERSISTENCE
  persistence = new FilePersistence(10);
#else
#endif

#ifdef JSON_SERIALIZER
  stream = new JsonArrayStream();
  serializer = new JsonSerializer();
#else
#endif

  Tracker::getInstance().activateTracker(DRAKHTAR_TRACKER);

  persistence->setValueStream(stream);
  persistence->setSerializer(serializer);

  Tracker::getInstance().setPersistence(persistence);
}
#endif
