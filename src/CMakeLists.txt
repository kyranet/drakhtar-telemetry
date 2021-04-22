set(TELEMETRY_SOURCES
	Tracker.cpp)

add_library(Telemetry SHARED ${TELEMETRY_SOURCES})
target_compile_features(Telemetry PUBLIC cxx_std_17)
target_include_directories(Telemetry
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)

if (MSVC)
    target_compile_options(Telemetry
      PRIVATE
      /W4
      /WX
      )
    get_target_property(opts Telemetry COMPILE_OPTIONS)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Telemetry
      PRIVATE
      -pedantic
      -pedantic-errors
      -Wall
      -Wextra
      -Werror
      -Wno-float-equal
      -Wno-padded
      )
else ()
    target_compile_options(Telemetry
      PRIVATE
      -pedantic
      -pedantic-errors
      -Wall
      -Wextra
      -Werror
      -Wconversion
      -Wno-c++98-compat
      -Wno-c++98-compat-pedantic
      -Wno-float-equal
      -Wno-padded
      -Wno-reserved-id-macro
      )
endif ()
