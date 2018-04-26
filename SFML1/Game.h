//
// Created by bswenson3 on 11/9/16.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RegularGameObject.h"
#include "AnimatedGameObject.h"

class Game {
public:
    //use default screen size
    Game();
    //run the game
    void run();

private:
    void processEvents();
    //update the game objects
    void update(sf::Time deltaT);
    //draw the scene
    void render();
    //handle input from the user
    void handlePlayerInput(sf::Keyboard::Key key, bool isDown);

    sf::RenderWindow m_window;

    AnimatedGameObject m2_player;
    AnimatedGameObject m3_player;
    AnimatedGameObject dancer; //maybe
    AnimatedGameObject shot;
    AnimatedGameObject shot2;

    RegularGameObject r1;
    RegularGameObject r2;
    RegularGameObject map;
    RegularGameObject crate;

    sf::Clock clock;
    sf::Clock clockSprite;
    sf::Clock clockDance;
    int startHalo = 0;
    int widthHalo = 145;
    int heightHalo = 220;
    int startCov = 0;
    int widthCov = 160;
    int heightCov = 300;
    int startXDance = 21;
    int startYDance = 175;
    int widthDance = 71;
    int heightDance = 95;
    int startXShot = 248;
    int startYShot = 42;
    int widthShot = 28;
    int heightShot = 30;
    bool shotOff = false;
    int startXShot2 = 266;
    int startYShot2 = 42;
    int widthShot2 = 28;
    int heightShot2 = 30;
    bool shotOff2 = false;
    sf::IntRect rect1 = sf::IntRect(startHalo, 0, widthHalo, heightHalo);
    sf::IntRect rect2 = sf::IntRect(startCov, 0, widthCov, heightCov);
    sf::IntRect rect3 = sf::IntRect(startXDance,startYDance, widthDance, heightDance);
    sf::IntRect rect4 = sf::IntRect(0, 0, 0, 0);
    sf::IntRect rect5 = sf::IntRect(0, 0, 0, 0);

    std::vector<GameObject*> vecObj = {};
    std::vector<sf::IntRect> vecRect = {rect1, rect1, rect2, rect3, rect4, rect5, rect4, rect4};


    //TODO::these should be moved to game object
    float m_speed = 120.0f;
    bool m_left = false;
    bool m_right = false;
    bool m_up = false;
    bool m_down = false;

    float m2_speed = 400.0f;
    bool m2_left = false;
    bool m2_right = false;
    bool m2_up = false;
    bool m2_down = false;

    float m3_speed = 400.0f;
    bool m3_left = false;
    bool m3_right = false;
    bool m3_up = false;
    bool m3_down = false;

    float shot_speed = 1000.0f;
};


