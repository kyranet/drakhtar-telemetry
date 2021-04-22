set(TELEMETRY_SOURCES
	Tracker.cpp)

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
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(telemetry
		PRIVATE
		-pedantic
		-pedantic-errors
		-Wall
		-Wextra
		-Wno-float-equal
		-Wno-padded
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
