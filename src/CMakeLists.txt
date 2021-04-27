set(TELEMETRY_SOURCES
	Configuration.cpp
	Tracker.cpp
	Persistence/FilePersistence.cpp
	Persistence/IPersistence.cpp
	Serialization/JsonSerializer.cpp
	TrackerAssets/PlayTracker.cpp
	TrackerEvents/EndEvent.cpp
	TrackerEvents/LevelEndEvent.cpp
	TrackerEvents/LevelStartEvent.cpp
	TrackerEvents/PlayerTurnEndEvent.cpp
	TrackerEvents/PlayerTurnStartEvent.cpp
	TrackerEvents/RoundEndEvent.cpp
	TrackerEvents/RoundStartEvent.cpp
	TrackerEvents/SessionEndEvent.cpp
	TrackerEvents/SessionStartEvent.cpp
	TrackerEvents/TrackerEvent.cpp)

add_library(telemetry SHARED ${TELEMETRY_SOURCES})
target_compile_features(telemetry PUBLIC cxx_std_17)
target_include_directories(telemetry
	PUBLIC
	$<BUILD_INTERFACE:${telemetry_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)

if (MSVC)
	target_compile_options(telemetry
		PRIVATE
		/W4
	)
	get_target_property(opts telemetry COMPILE_OPTIONS)
endif ()
