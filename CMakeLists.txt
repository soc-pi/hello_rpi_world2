cmake_minimum_required(VERSION 3.20)

# Set the project name
project(rpi_pwm)
SET (APPLICATION_NAME rpi_pwm)

SET (APPLICATION_COPYRIGHT_YEARS "2025")
SET (APPLICATION_VERSION_MAJOR 1)
SET (APPLICATION_VERSION_MINOR 0)
SET (APPLICATION_VERSION_PATCH 0)
SET (APPLICATION_VERSION_TYPE DS1)
SET (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")
SET (APPLICATION_VENDOR_ID "com.soccentric")
SET (APPLICATION_VENDOR_NAME "Soccentric")
SET (APPLICATION_VENDOR_URL "soccentric.com")
SET (APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")

#
# Configurable Options
#
OPTION (SERVED_BUILD_SHARED "Build shared object" ON)
OPTION (SERVED_BUILD_STATIC "Build static library" OFF)
OPTION (SERVED_BUILD_TESTS "Build unit test suite" ON)
OPTION (SERVED_BUILD_EXAMPLES "Build examples" ON)
OPTION (SERVED_BUILD_RPM "Build RPM package" OFF)
OPTION (SERVED_BUILD_DEB "Build DEB package" OFF)

#
# Debugging Options
#
SET (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release

# Add include directories
include_directories(src/include)

# Add subdirectories
add_subdirectory(src)


# Enable testing
enable_testing()

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add compiler warnings
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

