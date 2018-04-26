#include <iostream>
#include "Game.h"
#include <thread>
#include "HighScore.h"

void loadingThread() {
    std::cout<< "We are in the Thread!" <<std::endl;
}

int main() {

    std::thread t1(loadingThread);
    t1.join();
    Game game;
    game.run();

    return 0;
}