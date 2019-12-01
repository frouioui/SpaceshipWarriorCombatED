cmake_minimum_required(VERSION 3.10)
project(r-type)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3")
#set (CMAKE_SHARED_LINKER_FLAGS "-Wl")

set(GAME_ENGINE_LIB GameEngine/EntityManager.cpp
                    GameEngine/GameEngine.cpp
                    GameEngine/System/Render.cpp
                    GameEngine/System/Physic.cpp
                    GameEngine/System/Collision.cpp
                    GameEngine/System/DestroyEntity.cpp
                    )
add_library(game_engine STATIC ${GAME_ENGINE_LIB})

set(ERROR_LIB Error/Error.cpp)
add_library(error STATIC ${ERROR_LIB})

# Shared Lib
add_definitions("-fPIC")
add_library(Wall SHARED ${r-type_SOURCE_DIR}/Game/Object/Wall/Wall.cpp
                        ${r-type_SOURCE_DIR}/Game/Object/Wall/WallSystem.cpp)
add_library(Asteroid SHARED ${r-type_SOURCE_DIR}/Game/Object/Random/Asteroid.cpp)
add_library(Rusher SHARED ${r-type_SOURCE_DIR}/Game/Enemy/Rusher/Rusher.cpp)

set_target_properties(Wall PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${r-type_SOURCE_DIR}/Game/Object/Wall/lib)
set_target_properties(Asteroid PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${r-type_SOURCE_DIR}/Game/Object/Random/lib)
set_target_properties(Rusher PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${r-type_SOURCE_DIR}/Game/Enemy/lib)

include_directories(${r-type_SOURCE_DIR}/GameEngine
                    ${r-type_SOURCE_DIR}/GameEngine/Component
                    ${r-type_SOURCE_DIR}/GameEngine/System
                    ${r-type_SOURCE_DIR}/Error
                    ${r-type_SOURCE_DIR}/Sfml
                    ${r-type_SOURCE_DIR}/Loader
                    ${r-type_SOURCE_DIR}/Game/Rtype
                    ${r-type_SOURCE_DIR}/Game/Enemy
                    ${r-type_SOURCE_DIR}/Game/Object
                    ${r-type_SOURCE_DIR}/Game/Player
                    ${r-type_SOURCE_DIR}/client/include
                    ${r-type_SOURCE_DIR}/server/include
                    ${r-type_SOURCE_DIR}/Game
                    ${r-type_SOURCE_DIR}/Sfml/Assets
                    ${r-type_SOURCE_DIR}/lib/udp/include
                    )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Server sources (except main)
set(SERVER_SRC  GameEngine/EntityManager.cpp
                GameEngine/GameEngine.cpp
                GameEngine/System/Render.cpp
                GameEngine/System/Physic.cpp
                GameEngine/System/Collision.cpp
                GameEngine/System/DestroyEntity.cpp
                Game/AGame.cpp
                Game/Player/Player.cpp
                Game/Rtype/Rtype.cpp
                server/src/Server.cpp
                server/src/room/Room.cpp
                server/src/room/RoomManager.cpp
                server/src/client/Client.cpp
                server/src/client/ClientManager.cpp
                lib/udp/src/Packet.cpp
                lib/udp/src/UDP.cpp
                Error/Error.cpp
                Loader/Loader.cpp
                )

# Server main
set(SERVER_SRC_MAIN ./server/src/main.cpp ${SERVER_SRC})

# Client sources (except main)
set(CLIENT_SRC  client/src/Client.cpp
                client/src/network/NetworkConfig.cpp
                client/src/network/NetworkManager.cpp
                client/src/network/player/Player.cpp
                Error/Error.cpp
                Sfml/Sfml.cpp
                Sfml/Assets/AAsset.cpp
                Sfml/Assets/AssetsFactory.cpp
                Sfml/Assets/Player0.cpp
                Sfml/Assets/Player1.cpp
                Sfml/Assets/Player2.cpp
                Sfml/Assets/Player3.cpp
                Sfml/Assets/PlayerDie.cpp
                Sfml/Assets/PlayerShoot0.cpp
                Sfml/Assets/PlayerShoot1.cpp
                lib/udp/src/Packet.cpp
                lib/udp/src/UDP.cpp
                )

# Client main
set(CLIENT_SRC_MAIN client/src/main.cpp ${CLIENT_SRC})

# Executable
add_executable(r-type_server ${SERVER_SRC_MAIN})
add_executable(r-type_client ${CLIENT_SRC_MAIN})

add_dependencies(r-type_server game_engine)
add_dependencies(r-type_client game_engine)
add_dependencies(Wall game_engine)
add_dependencies(Asteroid game_engine)
add_dependencies(Rusher game_engine)


target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})
target_link_libraries(Wall -L. game_engine error)
target_link_libraries(Asteroid -L. game_engine error)
target_link_libraries(Rusher -L. game_engine error)


# mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .