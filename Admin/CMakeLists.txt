cmake_minimum_required(VERSION 3.19)
project(Admin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets RemoteObjects)

qt_standard_project_setup()

qt_add_executable(Admin
    WIN32 MACOSX_BUNDLE
    main.cpp
    admin.h admin.cpp
    adminmainwindow.h adminmainwindow.cpp adminmainwindow.ui
    productsmanagerwidget.h productsmanagerwidget.cpp productsmanagerwidget.ui
    adminproductwidget.h adminproductwidget.cpp adminproductwidget.ui
    producteditdialog.h producteditdialog.cpp producteditdialog.ui
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
  ../shared.rep
  ../Catalogue.rep
  ../user.rep
  ../admin.rep
)

qt_generate_deploy_app_script(
    TARGET Admin
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

target_include_directories(Admin PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
