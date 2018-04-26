//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"
#include <iostream>

Game::Game() :
    m_window(sf::VideoMode(2560, 1440), "Cooler Game")
{
    //load the player
    //m1_player.load("Mario.png");
  map.load("Map.jpg");
  r1.load("ChiefShip.png");
  r2.load("Hunter.png");
  crate.load("Crates.png");
  m2_player.load("MasterChiefOriginal1.png", sf::IntRect(startHalo,0,widthHalo,heightHalo));
  m3_player.load("Covenant1.png",sf::IntRect(startCov,0,widthCov,heightCov));
  dancer.load("ChiefDance.png", sf::IntRect(startXDance, startYDance, widthDance, heightDance));
  shot.load("shot2.png",sf::IntRect(0,0,0,0));
  shot2.load("shot5.png",sf::IntRect(0,0,0,0));


  m2_player.setPosition(500.0f,1200.0f);
  m3_player.setPosition(2000.0f,1200.0f);
  dancer.setPosition(1290.0f, 1001.0f);
  crate.setPosition(1100.0f, 1250.0f);
  r1.setPosition(60.0f, 450.0f);
  r2.setPosition(2200.0f, 1000.0f);
  shot.setPosition(m2_player.getPosition().x+120.0f,m2_player.getPosition().y+5.0f);
  shot2.setPosition(m3_player.getPosition().x-90.0f,m3_player.getPosition().y+40.0f);

  //size him.  trial and error to get correct values
    //m1_player.setScale(.1f);
  dancer.setScale(3.0f);
  crate.setScale(1.5f);
  r1.setScale(.3f);
  m3_player.setScale(.8f);
  map.setScale(2.5f);
  shot.setScale(4.0f);
  shot2.setScale(4.0f);

  vecObj = {&map, &m2_player, &m3_player, &dancer, &shot, &shot2, &crate, &r1, &r2,};
}

void Game::run() {
    while(m_window.isOpen()) {
        sf::Time deltaT = clock.restart();
        processEvents();
        update(deltaT);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
      switch (event.type) {
          case sf::Event::KeyPressed:
            //handle key down here
            if (clockSprite.getElapsedTime().asSeconds() > 0.09f) {
              if (((event.key.code == sf::Keyboard::A) || (event.key.code == sf::Keyboard::D)
                  || (event.key.code == sf::Keyboard::W) || (event.key.code == sf::Keyboard::S))
                  && ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::Right)
                     || (event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down))) {
                if (vecRect[1].left == widthHalo * 9)
                  vecRect[1] = sf::IntRect(startHalo, 0, widthHalo, heightHalo);
                if (vecRect[2].left == widthCov * 5)
                  vecRect[2] = sf::IntRect(startCov, 0, widthCov, heightCov);
                else
                  vecRect[1].left += widthHalo;
                  vecRect[2].left += widthCov;
              }

              if ((event.key.code == sf::Keyboard::A) || (event.key.code == sf::Keyboard::D)
                || (event.key.code == sf::Keyboard::W) || (event.key.code == sf::Keyboard::S)) {
                if (vecRect[1].left >= widthHalo * 9)
                  vecRect[1] = sf::IntRect(startHalo, 0, widthHalo, heightHalo);
                else
                  vecRect[1].left += widthHalo + 2;
              }
              if ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::Right)
                  || (event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down)) {
                if (vecRect[2].left == widthCov * 5)
                  vecRect[2] = sf::IntRect(startCov, 0, widthCov, heightCov);
                else
                  vecRect[2].left += widthCov;
              }
              if (event.key.code == sf::Keyboard::Space) {
                shotOff = true;
                vecRect[4] = sf::IntRect(startXShot,startYShot, widthShot, heightShot);
              }
              if (event.key.code == sf::Keyboard::P) {
                shotOff2 = true;
                vecRect[5] = sf::IntRect(startXShot2+ widthShot2*6, startYShot2, widthShot2, heightShot2);
              }
              clockSprite.restart();
            }
            handlePlayerInput(event.key.code, true);
            break;
          case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
          break;

          case sf::Event::Closed:
            m_window.close();
          break;
      }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Left)
        m3_left = isDown;
    if(key == sf::Keyboard::Right)
        m3_right = isDown;
    if(key == sf::Keyboard::Up)
        m3_up = isDown;
    if(key == sf::Keyboard::Down)
        m3_down = isDown;
    if(key == sf::Keyboard::A)
      m2_left = isDown;
    if(key == sf::Keyboard::D)
      m2_right = isDown;
    if(key == sf::Keyboard::W)
      m2_up = isDown;
    if(key == sf::Keyboard::S)
      m2_down = isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);

    if(m2_up) {
      movement.y -= m2_speed;
      vecObj[1]->move(movement * deltaT.asSeconds());
    }
    if(m2_down) {
      movement.y += m2_speed;
      vecObj[1]->move(movement * deltaT.asSeconds());
    }
    if(m2_left) {
      movement.x -= m2_speed;
      vecObj[1]->move(movement * deltaT.asSeconds());
    }
    if(m2_right) {
      movement.x += m2_speed;
      vecObj[1]->move(movement * deltaT.asSeconds());
    }

    movement = {0.0f,0.0f};

    if(m3_up) {
      movement.y -= m3_speed;
      vecObj[2]->move(movement * deltaT.asSeconds());
    }
      if(m3_down) {
      movement.y += m3_speed;
      vecObj[2]->move(movement * deltaT.asSeconds());
    }
      if(m3_left) {
      movement.x -= m3_speed;
      vecObj[2]->move(movement * deltaT.asSeconds());
    }
      if(m3_right) {
      movement.x += m3_speed;
      vecObj[2]->move(movement * deltaT.asSeconds());
    }

    movement = {0.0f,0.0f};


}

void Game::render() {
    sf::Vector2f movement(0.0f, 0.0f);
    sf::Vector2f movement2(0.0f, 0.0f);
    if (clockDance.getElapsedTime().asSeconds() > 0.05f) {
      if (vecRect[3].left >= widthDance * 6)
        vecRect[3] = sf::IntRect(startXDance, startYDance, widthDance, heightDance);
      else
        vecRect[3].left += widthDance;
      if (shotOff) {
        movement.x += shot_speed;
        vecObj[4]->move(movement * clockDance.getElapsedTime().asSeconds());
        if (vecRect[4].left == widthShot * 5 + startXShot)
          vecRect[4] = sf::IntRect(widthShot * 5 + startXShot,startYShot, widthShot, heightShot);
        else if (vecObj[4]->getPosition().x >= 2560.0f) {
          vecRect[4] = sf::IntRect(0, 0, 0, 0);
          shot.setPosition(m2_player.getPosition().x+120.0f,m2_player.getPosition().y+5.0f);
          shotOff = false;
        }
        else
          vecRect[4].left += widthShot;
      }
      if (shotOff2) {
        movement2.x -= shot_speed;
        vecObj[5]->move(movement2 * clockDance.getElapsedTime().asSeconds());
        if (vecRect[5].left == (startXShot2 + widthShot2 * 6) - widthShot2*5)
          vecRect[5] = sf::IntRect((startXShot2 + widthShot2 * 6) - widthShot2*5,startYShot2, widthShot2, heightShot2);
        else if (vecObj[5]->getPosition().x <= -1.0f) {
          vecRect[5] = sf::IntRect(0, 0, 0, 0);
          shot2.setPosition(m3_player.getPosition().x-90.0f,m3_player.getPosition().y+40.0f);
          shotOff2 = false;
        }
        else
          vecRect[5].left -= widthShot;
      }
      clockDance.restart();
    }
    /*
    std::cout<< vecObj[2]->getPosition().x << std::endl;
    std::cout<< vecObj[2]->getPosition().y << std::endl;
    std::cout<< vecObj[4]->getPosition().x << std::endl;
    std::cout<< vecObj[4]->getPosition().y << std::endl;
    */
    if ((vecObj[4]->getPosition().x >= vecObj[2]->getPosition().x)
        && (vecObj[4]->getPosition().x <= (vecObj[2]->getPosition().x + widthCov))
        && (vecObj[4]->getPosition().y >= vecObj[2]->getPosition().y)
           && (vecObj[4]->getPosition().y <= (vecObj[2]->getPosition().y + heightCov)))
      std::cout<< "Game Over!! Master Chief Wins!!" << std::endl;

    if ((vecObj[5]->getPosition().x >= vecObj[1]->getPosition().x)
            &&(vecObj[5]->getPosition().x <= (vecObj[1]->getPosition().x + widthHalo))
            &&(vecObj[5]->getPosition().y >= vecObj[1]->getPosition().y)
            &&(vecObj[5]->getPosition().y <= (vecObj[1]->getPosition().y + heightHalo)) ) {
      std::cout<< "Game Over!! Elite Wins!!" << std::endl;
    }

    m_window.clear();

    for (int i = 0; i<vecObj.size(); i++)
      vecObj[i]->draw(m_window, vecRect[i]);

    m_window.display();
}