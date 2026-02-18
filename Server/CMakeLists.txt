cmake_minimum_required(VERSION 3.16)

project(Server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core RemoteObjects)

add_executable(Server
  main.cpp
)

target_link_libraries(Server PUBLIC
    Qt::Core
    Qt::RemoteObjects
)

install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


qt6_add_repc_replicas(Server
    ../Catalogue.rep
)
