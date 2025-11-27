cmake_minimum_required(VERSION 3.25)

project(roboSim)

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
