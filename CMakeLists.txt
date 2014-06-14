cmake_minimum_required(VERSION 2.8)

#hush, annoying warnings
if(POLICY CMP0017)
 cmake_policy(SET CMP0017 NEW)
endif(POLICY CMP0017)

project(WPITestHarness)

enable_testing()

#libeurointroduction headers
find_path(libeurointroduction_headers_FOUND Ptr.h PATHS /usr/include/eurointroduction/Util /usr/local/include/eurointroduction/Util)
if(NOT libeurointroduction_headers_FOUND)
  message(FATAL_ERROR "Can't find libeurointroduction headers")
endif()

#libeurointroduction library
find_path(libeurointroduction_shared_library_FOUND libeurointroduction.so PATHS /usr/lib /usr/local/lib)
find_path(libeurointroduction_static_library_FOUND libeurointroduction.a PATHS /usr/lib /usr/local/lib)
if((NOT libeurointroduction_shared_library_FOUND) AND (NOT libeurointroduction_static_library_FOUND))
  message(FATAL_ERROR "Can't find libeurointroduction library")
endif()

#control default install prefix, code is hardcoded to load files from /usr/share/WPILibTestHarness
SET(WPIHARNESS_INSTALL_PREFIX "/usr" CACHE PATH "Prefix prepended to
install directories")
SET(CMAKE_INSTALL_PREFIX "${WPIHARNESS_INSTALL_PREFIX}" CACHE INTERNAL "Prefix
prepended to install directories" FORCE)

# The version number.
set (CPR_VERSION_MAJOR 1)
set (CPR_VERSION_MINOR 0)

#enables debug flags
SET(CMAKE_BUILD_TYPE relwithdebinfo)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} --std=gnu++11 -Wall -pthread -Og ${wxWidgets_DEFINITIONS}")

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g")

set(header_destination "include/wpiharness")

#deal with WxWidgets
find_package(wxWidgets COMPONENTS core base xrc adv REQUIRED)

include("${wxWidgets_USE_FILE}")

#deal with Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS date_time system REQUIRED) 

include_directories(${Boost_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness")

add_subdirectory("WPILibTestHarness")
add_subdirectory("DefaultCode")
add_subdirectory("DriverStationTest")
