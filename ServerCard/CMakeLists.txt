cmake_minimum_required(VERSION 3.14)

project(ServerCard LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)



set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)






add_executable(ServerCard
  main.cpp
  serversocket.h
  serversocket.cpp
  cardserver.h
  cardserver.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(ServerCard Qt${QT_VERSION_MAJOR}::Core Qt6::Network)
