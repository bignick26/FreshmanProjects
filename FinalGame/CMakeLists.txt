cmake_minimum_required(VERSION 3.6)
project(FinalGame)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "FinalGame")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        Game.cpp Game.h GameObject.cpp GameObject.h
        AnimatedGameObject.cpp AnimatedGameObject.h
        RegularGameObject.cpp RegularGameObject.h HighScore.cpp HighScore.h)

#copy file to where my executable is
file(COPY "Images/BrianFace.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/Slide1.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/Slide2.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/PressStart2P.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/TibetanMachineUni.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/HighScore.txt" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/StoryBackground.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Images/titleintro2.png" DESTINATION "${CMAKE_BINARY_DIR}")


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})