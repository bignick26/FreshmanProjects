//
// Created by brick on 11/17/16.
//

#include "AnimatedGameObject.h"

AnimatedGameObject::AnimatedGameObject() {

}

bool AnimatedGameObject::load(const std::string& filename) {
  if(a_texture.loadFromFile(filename)) {
    a_filename = filename;
    a_sprite.setTextureRect(sf::IntRect(0,0,52,73)); //dimensions of Master Chief: 615 (51.25) x 293 (73.25) pixels
    a_sprite.setTexture(a_texture);
    a_valid = true;
    return true;
  }
  return false;
}

bool AnimatedGameObject::load(const std::string& filename, sf::IntRect rect) {
  if(a_texture.loadFromFile(filename)) {
    a_filename = filename;
    a_sprite.setTextureRect(rect); //dimensions of Master Chief: 615 (51.25) x 293 (73.25) pixels
    a_sprite.setTexture(a_texture);
    a_valid = true;
    return true;
  }
  return false;
}

void AnimatedGameObject::draw(sf::RenderWindow& window, sf::IntRect rect) {
  if(a_valid) {
    a_sprite.setTextureRect(rect); //dimensions of Master Chief: 615 (51.25) x 293 (73.25) pixels
    window.draw(a_sprite);
  }
}

void AnimatedGameObject::draw(sf::RenderWindow& window) {
  if(a_valid) {
    window.draw(a_sprite);
  }
}

void AnimatedGameObject::move(sf::Vector2f loc) {
  if(a_valid)
    a_sprite.move(loc);
}

void AnimatedGameObject::setPosition(float x, float y) {
  if(a_valid)
    a_sprite.setPosition(x, y);
}

sf::Vector2f AnimatedGameObject::getPosition() const {
  if(a_valid)
    return a_sprite.getPosition();
  else
    return sf::Vector2f(0, 0);
}

float AnimatedGameObject::getHeight() const {
  return a_sprite.getLocalBounds().height;
}

float AnimatedGameObject::getWidth() const {
  return a_sprite.getLocalBounds().width;
}

void AnimatedGameObject::setScale(float scale) {
  if(a_valid)
    a_sprite.setScale(scale, scale);
}

void AnimatedGameObject::update(float deltaT) {

}
