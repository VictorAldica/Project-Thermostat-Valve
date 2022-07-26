cmake_minimum_required(VERSION 3.0.0)
project(ProjectThermostatValve VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(component date room room_manager scheduler sensor thermostat valve server client )
add_executable(ProjectThermostatValve src/main.cpp component/component.cpp date/date.cpp 
room_manager/room_manager.cpp room/room.cpp scheduler/scheduler.cpp sensor/sensor.cpp 
thermostat/thermostat.cpp valve/valve.cpp) 

add_subdirectory(server)
add_subdirectory(client)
install(TARGETS Client Server DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
