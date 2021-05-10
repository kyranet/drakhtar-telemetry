// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once

#define TELEMETRY
#define FILE_PERSISTENCE
#define JSON_SERIALIZER

#ifdef TELEMETRY
#include "Tracker.h"

#ifdef FILE_PERSISTENCE
#include "Persistence/FilePersistence.h"
#else
#endif

#ifdef JSON_SERIALIZER
#include "Serialization/Json/JsonArrayStream.h"
#include "Serialization/Json/JsonSerializer.h"
#else
#endif

void TrackerConfiguration();

#endif
