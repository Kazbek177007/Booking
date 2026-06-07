cmake_minimum_required(VERSION 3.19)
project(Admin LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets RemoteObjects)

qt_standard_project_setup()

qt_add_executable(Admin
    WIN32 MACOSX_BUNDLE
    main.cpp
    admin.h admin.cpp
)

target_link_libraries(Admin
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::RemoteObjects
)

install(TARGETS Admin
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt6_add_repc_replicas(Admin
  ../catalogue.rep
  ../user.rep
  ../admin.rep
)

qt_generate_deploy_app_script(
    TARGET Admin
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
