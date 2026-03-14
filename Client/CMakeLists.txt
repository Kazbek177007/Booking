cmake_minimum_required(VERSION 3.16)

project(Client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core RemoteObjects Widgets)


qt_add_executable(Client
  main.cpp
  catalogue.h catalogue.cpp



)

target_link_libraries(Client PUBLIC
    Qt::Core
    Qt::RemoteObjects
    Qt::Widgets
)

install(TARGETS Client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


qt6_add_repc_replicas(Client
  ../catalogue.rep
  ../user.rep
)

target_include_directories(Client PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
