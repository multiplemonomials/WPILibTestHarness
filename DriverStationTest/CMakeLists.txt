
#override the installed wpiharness headers with our own
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness/WPILib")
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness/VxWorks")


add_executable(DriverStationTest DriverStationLCD.cpp DriverStationLCD.h MyRobot.cpp)

target_link_libraries(DriverStationTest WPILibTestHarness eurointroduction ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})

add_test(TestDriverStation DriverStationTest)
