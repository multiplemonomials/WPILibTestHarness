include_directories(${wxWidgets_INCLUDE_DIRS})
include_directories("WPILib")
include_directories("VxWorks")


file(GLOB wpiharness_SRC
    "*.h"
    "*.cpp"
    "Simulator/*.h"
    "Simulator/*.cpp"
    "VxWorks/*.h"
    "WPILib/*.h"
    "WPILib/*.cpp"
    "WPILib/ChipObject/*.h"
    "WPILib/ChipObject/*.cpp"
    "WPILib/NetworkCommunication/*.h"
    "WPILib/NetworkCommunication/*.cpp"
)

add_library(WPILibTestHarness ${wpiharness_SRC})

target_link_libraries(WPILibTestHarness)

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
    "Simulator/*.h"
)

install(FILES ${simulator_HEADERS} DESTINATION ${header_destination}/Simulator)

#some additional headers
install(FILES WPILib/ChipObject/NiRio.h DESTINATION "${header_destination}/WPILib/ChipObject")

install(FILES WPILib/NetworkCommunication/FRCComm.h DESTINATION "${header_destination}/WPILib/NetworkCommunication")

#resource file
install(FILES WPILibTestHarness.xrc DESTINATION "share/WPILibTestHarness")
