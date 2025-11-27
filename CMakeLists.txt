cmake_minimum_required(VERSION 3.25)

project(roboSim VERSION 0.1.0 LANGUAGES CXX)

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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

target_link_libraries(roboSim 
        PRIVATE 
        SDL3::SDL3
        eigen
)
