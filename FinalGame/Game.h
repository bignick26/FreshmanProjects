//
// Created by bswenson3 on 11/9/16.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RegularGameObject.h"
#include "AnimatedGameObject.h"
#include "HighScore.h"
#include <fstream>

class Game {
public:
    //use default screen size
    Game();
    //run the game
    void run();

private:

    //TitleOn:
    void processTitleEvents();


    void processEvents();
    //update the game objects
    void update(sf::Time deltaT);
    //draw the scene
    void render();
    //handle input from the user
    void handlePlayerInput(sf::Keyboard::Key key, bool isDown);

    //GAME VARIABLES!!
    sf::RenderWindow game_window;
    HighScore high_score;

    //Title Screen:
    RegularGameObject title_screen;
    RegularGameObject title_screen1;
    RegularGameObject title_screen2;
    sf::Clock title_clock;
    float pauseTime = 5.0f;
    bool title1 = true;
    bool titleOn = true;

    //Story Screen:
    RegularGameObject story_screen;
    AnimatedGameObject story_text;
    bool storyOn = true;

    //Other Objects:



    //Sprite Rectangles
    sf::IntRect rect1 = sf::IntRect(0, 0, 0, 0);

    //Vectors:
    std::vector<GameObject*> vecObj = {};
    std::vector<sf::IntRect> vecRect = {};

    //HighScore:
    int score;

    //TODO::these should be moved to game object
    float m_speed = 120.0f;
    bool key_left = false;
    bool key_right = false;
    bool key_up = false;
    bool key_down = false;
};


