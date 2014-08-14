cmake_minimum_required(VERSION 2.8)

#hush, annoying warnings
if(POLICY CMP0017)
 cmake_policy(SET CMP0017 NEW)
endif(POLICY CMP0017)

project(WPITestHarness)

enable_testing()

include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
include(${CMAKE_ROOT}/Modules/CheckIncludeFileCXX.cmake)
include(${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)

#control default install prefix, code is hardcoded to load files from /usr/share/WPILibTestHarness
SET(WPIHARNESS_INSTALL_PREFIX "/usr" CACHE PATH "Prefix prepended to
install directories")
SET(CMAKE_INSTALL_PREFIX "${WPIHARNESS_INSTALL_PREFIX}" CACHE INTERNAL "Prefix
prepended to install directories" FORCE)

# The version number.
set (CPR_VERSION_MAJOR 1)
set (CPR_VERSION_MINOR 0)

#get wxWidgets build flags
execute_process(COMMAND "wx-config --cppflags" OUTPUT_VARIABLE wx_CPPFLAGS)

#enables debug flags
SET(CMAKE_BUILD_TYPE relwithdebinfo)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} --std=gnu++11 -Wall -pthread ${wxWidgets_DEFINITIONS}")

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g")

set(header_destination "include/wpiharness")

#deal with WxWidgets
find_package(wxWidgets COMPONENTS core base xrc adv REQUIRED)
find_package(Boost COMPONENTS date_time system REQUIRED)

#set up path to look for eurointroduction
set(CMAKE_REQUIRED_INCLUDES "/usr/eurointroduction")
check_include_file_cxx(EzLogger/LogCore.h HAVE_EzLogger REQUIRED)

include("${wxWidgets_USE_FILE}")
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness")

add_subdirectory("WPILibTestHarness")
add_subdirectory("DefaultCode")
add_subdirectory("DriverStationTest") 
