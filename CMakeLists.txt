cmake_minimum_required(VERSION 3.10)
project(r-type)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${r-type_SOURCE_DIR}/GameEngine
                    ${r-type_SOURCE_DIR}/GameEngine/Component
                    ${r-type_SOURCE_DIR}/GameEngine/System
                    ${r-type_SOURCE_DIR}/Sfml
                    ${r-type_SOURCE_DIR}/Rtype)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Server sources (except main)
set(SERVER_SRC  GameEngine/EntityManager.cpp
                GameEngine/GameEngine.cpp
                GameEngine/System/Render.cpp
                Rtype/Rtype.cpp
                Sfml/Sfml.cpp)

# Server main
set(SERVER_SRC_MAIN ./Rtype/main.cpp ${SERVER_SRC})

# Client sources (except main)
set(CLIENT_SRC  client/Client.cpp
                Sfml/Sfml.cpp)

# Client main
set(CLIENT_SRC_MAIN client/main.cpp ${CLIENT_SRC})

# Executable
add_executable(r-type_server ${SERVER_SRC_MAIN})
add_executable(r-type_client ${CLIENT_SRC_MAIN})

target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

# mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .