cmake_minimum_required(VERSION 3.0.0)
project(ProjectThermostatValve VERSION 0.1.0)


project(ProjectThermostatValve)

add_subdirectory(server)
add_subdirectory(client)

set_property(TARGET Client Server PROPERTY CXX_STANDARD 17)

install(TARGETS Client Server DESTINATION bin)