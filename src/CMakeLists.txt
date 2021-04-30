# If it's not Windows, let's include the UUID library from Linux
if (NOT WIN32)
	find_package(PkgConfig REQUIRED)
	pkg_search_module(UUID REQUIRED uuid)
endif ()

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
	TrackerEvents/TrackerEvent.cpp
	TrackerEvents/PauseStartEvent.cpp
	TrackerEvents/PauseEndEvent.cpp
	TrackerEvents/BuyUnitsEvent.cpp)

add_library(telemetry SHARED ${TELEMETRY_SOURCES})
target_compile_features(telemetry PUBLIC cxx_std_17)

# If Linux, we need to make sure we include and link to libuuid.
if (NOT WIN32)
	target_include_directories(telemetry
		PUBLIC
		$<BUILD_INTERFACE:${telemetry_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${UUID_INCLUDE_DIRS})
	target_link_libraries(telemetry ${UUID_LIBRARIES})
else ()
	target_include_directories(telemetry
			PUBLIC
			$<BUILD_INTERFACE:${telemetry_SOURCE_DIR}/include>
			$<INSTALL_INTERFACE:include>)
endif ()

if (MSVC)
	target_compile_options(telemetry
		PRIVATE
		/W4
	)
	get_target_property(opts telemetry COMPILE_OPTIONS)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(telemetry
		PRIVATE
		-pedantic
		-pedantic-errors
		-Wall
		-Wextra
		-Wno-float-equal
		-Wno-padded
		-luuid
	)
else ()
	target_compile_options(telemetry
		PRIVATE
		-pedantic
		-pedantic-errors
		-Wall
		-Wextra
		-Wconversion
		-Wno-c++98-compat
		-Wno-c++98-compat-pedantic
		-Wno-float-equal
		-Wno-padded
		-Wno-reserved-id-macro
	)
endif ()
