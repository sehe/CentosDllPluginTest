project(CentosPlugin)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
find_package(PkgConfig)

find_package(Boost 1.53.0 COMPONENTS system)

ADD_DEFINITIONS(-DBOOST_ALLOW_DEPRECATED_HEADERS=1)

LINK_LIBRARIES(boost_system 
boost_filesystem
dl)

ADD_LIBRARY(plugin SHARED plugin.cpp)
ADD_EXECUTABLE(loader loader.cpp)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES("${Boost_LIBRARY_DIRS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic ") # -Wconversion
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections -Wl,--gc-sections")
#SET(CMAKE_LINK_LIBRARY_FLAG "-Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0 -DNDEBUG -O3 -pthread -march=native")
