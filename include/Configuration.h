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
#error "You must define a persistence type"
#endif

#if defined(JSON_SERIALIZER)
#include "Serialization/Json/JsonArrayStream.h"
#include "Serialization/Json/JsonSerializer.h"
#elif defined(XML_SERIALIZER)
#include "Serialization/Xml/XmlArrayStream.h"
#include "Serialization/Xml/XmlSerializer.h"
#else
#error "You must define a serializer type"
#endif

void TrackerConfiguration();
#endif
