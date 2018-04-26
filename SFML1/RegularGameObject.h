//
// Created by brick on 11/17/16.
//
#pragma once
#include "GameObject.h"

class RegularGameObject : public GameObject {
public:
    RegularGameObject();
    virtual bool load(const std::string& filename);
    virtual bool load(const std::string& filename, sf::IntRect rect) {};

    virtual void draw(sf::RenderWindow& window);
    virtual void draw(sf::RenderWindow& window, sf::IntRect rect);


    virtual void update(float deltaT);

    virtual void setPosition(float x, float y);

    virtual void move(sf::Vector2f);

    virtual sf::Vector2f getPosition() const;

    virtual float getHeight() const;

    virtual float getWidth() const;

    virtual void setScale(float scale);

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;
};

