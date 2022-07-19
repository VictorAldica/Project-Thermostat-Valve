cmake_minimum_required(VERSION 3.0.0)
project(ProjectThermostatValve VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(component date room room_manager scheduler sensor thermostat valve )
add_executable(ProjectThermostatValve src/main.cpp component/component.cpp date/date.cpp 
room_manager/room_manager.cpp room/room.cpp scheduler/scheduler.cpp sensor/sensor.cpp 
thermostat/thermostat.cpp valve/valve.cpp server/server.cpp client/client.cpp) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
