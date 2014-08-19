
#override the installed wpiharness headers with our own
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness/WPILib")
include_directories("${PROJECT_SOURCE_DIR}/WPILibTestHarness/VxWorks")


add_executable(DefaultCode WIN32 BuiltinDefaultCode.cpp)

target_link_libraries(DefaultCode WPILibTestHarness eurointroduction ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})

add_test(TestDefaultCode DefaultCode)
