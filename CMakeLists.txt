cmake_minimum_required(VERSION 3.25)

project(roboSim VERSION 0.1.0 LANGUAGES CXX C)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(eigen-master EXCLUDE_FROM_ALL)

add_executable(roboSim)
target_sources(roboSim
        PRIVATE
                src/main.cpp
                src/rigidBody.cpp

        PUBLIC
                FILE_SET projectHeaders
                TYPE HEADERS
                BASE_DIRS 
                        include
                FILES
                        include/rigidBody.hpp
)

add_library(logger)
target_sources(logger
        PRIVATE
                logger/logger.c
        PUBLIC
                FILE_SET loggerHeader
                TYPE HEADERS
                BASE_DIRS
                        logger
                FILES
                        logger/logger.h
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

target_link_libraries(roboSim 
        PRIVATE 
        SDL3::SDL3
        eigen
)
