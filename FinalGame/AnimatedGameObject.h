//
// Created by brick on 11/17/16.
//

#ifndef HOMEWORK5_ANIMATEDGAMEOBJECT_H
#define HOMEWORK5_ANIMATEDGAMEOBJECT_H
#include "GameObject.h"

class AnimatedGameObject : public GameObject {
public:
    AnimatedGameObject();

    virtual bool load(const std::string& filename);
    virtual bool load(const std::string& filename, sf::IntRect rect);

    virtual void draw(sf::RenderWindow& window);
    virtual void draw(sf::RenderWindow& window, sf::IntRect rect);

    virtual void update(float deltaT);

    virtual void setPosition(float x, float y);

    virtual void move(sf::Vector2f);

    virtual sf::Vector2f getPosition() const;

    virtual float getHeight() const;

    virtual float getWidth() const;

    virtual void setScale(float scale);

    sf::Sprite a_sprite;
    sf::Texture a_texture;

private:
    std::string a_filename;
    bool a_valid = false;
};


#endif //HOMEWORK5_ANIMATEDGAMEOBJECT_H
