// Demonstrate creating a spritesheet
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;
  sf::Texture texture;
  texture.loadFromFile("MasterChiefOriginal.png");

  sf::IntRect rectSourceSprite(0, 0, 51, 73);
  sf::Sprite sprite(texture, rectSourceSprite);
  sprite.setScale(3.5f,3.5f);
  sf::Clock clock;

  while (renderWindow.isOpen()) {
    while (renderWindow.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    if (clock.getElapsedTime().asSeconds() > 0.15f) {
      if (rectSourceSprite.left == 612)
        rectSourceSprite.left = 0;
      else
        rectSourceSprite.left += 51;

      sprite.setTextureRect(rectSourceSprite);
      clock.restart();
    }


    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}