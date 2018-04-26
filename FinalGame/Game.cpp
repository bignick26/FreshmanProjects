//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"
#include <iostream>

Game::Game() :
    game_window(sf::VideoMode(2560, 1440), "Lord of the Flies II: Rise of the Planet of the Flies")
{
    //load TITLE objects
    title_screen1.load("Slide1.png");
    title_screen2.load("Slide2.png");
    title_screen = title_screen2;

    //load STORY objects
    story_screen.load("StoryBackground.png");
    story_text.load("titleintro2.png");

    //size TITLE objects
    title_screen.setScale(2.0f);
    title_screen2.setScale(2.0f);
    title_screen1.setScale(2.0f);

    //size STORY objects
    story_screen.setScale(2.0f);
    story_text.setScale(1.0f);

    //Set High Score
    high_score.load("HighScore.txt");
    score = high_score.getScore();
    //high_score.print();
    //std::cout<< score <<std::endl;
    //high_score.setScore()


    //Instantiate Vector(s) to drawl, move, animate.. objects
    vecObj = {&title_screen,&high_score};
    vecRect = {rect1,rect1};
}



void Game::run() {
    sf::Clock clock;

    while(game_window.isOpen()) {
        if (titleOn) {
            sf::Time deltaT = clock.restart();
            processTitleEvents();
            render();
        }
        if (storyOn) {
            sf::Time deltaT = clock.restart();
            processEvents();
            update(deltaT);
            render();
        }
    }
    high_score.setScoreFile();
}

void Game::processTitleEvents() {
    sf::Event event;
    while(game_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                //handle key down here
                titleOn = false;
                vecObj = {&story_screen, &story_text};
                vecRect = {rect1, rect1};
                break;

            case sf::Event::KeyReleased:
                titleOn = false;
                vecObj = {&story_screen, &story_text};
                vecRect = {rect1, rect1};
                break;

            case sf::Event::Closed:
                game_window.close();
                break;
        }
    }
}

void Game::processEvents() {
    sf::Event event;
    while(game_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
            //handle key down here
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                high_score.setScoreFile();
                game_window.close();
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Left)
        key_left = isDown;
    if(key == sf::Keyboard::Right)
        key_right = isDown;
    if(key == sf::Keyboard::Up)
        key_up = isDown;
    if(key == sf::Keyboard::Down)
        key_down = isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);
    if(key_up)
        movement.y -= m_speed;
    if(key_down)
        movement.y += m_speed;
    if(key_left)
        movement.x -= m_speed;
    if(key_right)
        movement.x += m_speed;

    //title_screen.move(movement * deltaT.asSeconds());

}

void Game::render() {

    //Animation/Movement Rendering
    if(title_clock.getElapsedTime().asSeconds() > pauseTime) {
        if(title1) {
            title_screen = title_screen1;
            title1 = false;
        }
        else {
            title_screen = title_screen2;
            title1 = true;
        }
        //high_score.setScore("HighScore.txt");
        pauseTime = 0.5f;
        title_clock.restart();
        score += 1;
        high_score.setScore(score);
    }


    //Game Reloading
    game_window.clear();

    for (int i = 0; i<vecObj.size(); i++)
        vecObj[i]->draw(game_window);

    game_window.display();
}