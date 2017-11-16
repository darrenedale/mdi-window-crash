cmake_minimum_required(VERSION 3.0)

project(qmdi_window_segfault LANGUAGES CXX)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(QMdiMainWindowCrash
	main.cpp
        mainwindow.cpp
   	subwindow.cpp
)

set_target_properties(QMdiMainWindowCrash PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
)

target_link_libraries(QMdiMainWindowCrash Qt5::Core Qt5::Gui Qt5::Widgets)

