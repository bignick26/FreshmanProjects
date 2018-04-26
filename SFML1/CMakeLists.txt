cmake_minimum_required(VERSION 3.6)
project(Homework5)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "h5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        Game.cpp Game.h GameObject.cpp GameObject.h
        AnimatedGameObject.cpp AnimatedGameObject.h
        RegularGameObject.cpp RegularGameObject.h)

#copy file to where my executable is
file(COPY "content/Mario.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/MasterChiefOriginal.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/MasterChiefOriginal1.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/Covenant1.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/Hunter.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/ChiefShip.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/Map.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/Crates.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/ChiefDance.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/shot2.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/shot5.png" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})