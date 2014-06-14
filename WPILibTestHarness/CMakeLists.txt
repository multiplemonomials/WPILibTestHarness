include_directories(${wxWidgets_INCLUDE_DIRS})
include_directories("WPILib")
include_directories("VxWorks")


file(GLOB_RECURSE wpiharness_SRC
    "*.h"
    "*.cpp"
)

add_library(WPILibTestHarness ${wpiharness_SRC})

target_link_libraries(WPILibTestHarness ${wxWidgets_LIBRARIES})

install(TARGETS WPILibTestHarness DESTINATION lib)

#collect all headers from wpilib dir
file(GLOB fakewpi_HEADERS
    "WPILib/*.h"
)

install(FILES ${fakewpi_HEADERS} DESTINATION ${header_destination}/WPILib)

#collect all headers from VxWorks dir
file(GLOB vxworks_HEADERS
    "VxWorks/*.h"
)

install(FILES ${vxworks_HEADERS} DESTINATION ${header_destination})
install(FILES ${vxworks_HEADERS} DESTINATION ${header_destination}/VxWorks)

#collect all headers from Simulator dir
file(GLOB simulator_HEADERS
    "EzLogger/*.h"
)

install(FILES ${simulator_HEADERS} DESTINATION ${header_destination}/EzLogger)

#collect all headers from EzLogger dirs
file(GLOB ezlogger_HEADERS
    "EzLogger/*.h"
)

install(FILES ${ezlogger_HEADERS} DESTINATION ${header_destination}/EzLogger)

file(GLOB ezlogger_HEADERS
    "EzLogger/output/*.h"
)

install(FILES ${ezlogger_HEADERS} DESTINATION ${header_destination}/EzLogger)

file(GLOB ezlogger_HEADERS
    "EzLogger/output/formatters/*.h"
)

install(FILES ${ezlogger_HEADERS} DESTINATION ${header_destination}/EzLogger)

file(GLOB ezlogger_HEADERS
    "EzLogger/output/acceptors/*.h"
)

install(FILES ${ezlogger_HEADERS} DESTINATION ${header_destination}/EzLogger)

file(GLOB ezlogger_HEADERS
    "EzLogger/output/writers/*.h"
)

install(FILES ${ezlogger_HEADERS} DESTINATION ${header_destination}/EzLogger)


#some additional headers
install(FILES WPILib/ChipObject/NiRio.h DESTINATION "${header_destination}/WPILib/ChipObject")

install(FILES WPILib/NetworkCommunication/FRCComm.h DESTINATION "${header_destination}/WPILib/NetworkCommunication")

#resource file
install(FILES WPILibTestHarness.xrc DESTINATION "share/WPILibTestHarness")
