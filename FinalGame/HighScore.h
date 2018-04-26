//
// Created by brick on 12/11/16.
//

#ifndef FINALGAME_HIGHSCORE_H
#define FINALGAME_HIGHSCORE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObject.h"
#include <fstream>

class HighScore : public GameObject {
public:
    HighScore();
    virtual bool load(const std::string& filename);
    virtual bool load(const std::string& filename, sf::IntRect rect) {};

    int getScore();

    void setScore(int scoreIn);

    void setScoreFile();

    std::string getScoreFile( const std::string& filename);

    virtual void draw(sf::RenderWindow& window);
    virtual void draw(sf::RenderWindow& window, sf::IntRect rect) {};


    virtual void update(float deltaT) {};

    virtual void setPosition(float x, float y) {};


    virtual void move(sf::Vector2f) {};

    virtual sf::Vector2f getPosition() const {};

    virtual float getHeight() const {};

    virtual float getWidth() const {};

    virtual void setScale(float scale) {};

    void print();


private:

    sf::Text text;
    sf::Font font;
    std::string input = getScoreFile("HighScore.txt");

};


#endif //FINALGAME_HIGHSCORE_H
