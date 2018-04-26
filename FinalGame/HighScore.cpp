//
// Created by brick on 12/11/16.
//

#include "HighScore.h"
#include <iostream>

HighScore::HighScore() {
    text.setString("High Score: " + input);
    // Create a graphical text to display
    if (!font.loadFromFile("PressStart2P.ttf"))
        std::cout<< "Error" <<std::endl;
    text.setFont(font);
    text.setScale(2.5f,2.5f);
    text.setPosition(700.0f,1180.0f);
}

std::string HighScore::getScoreFile(const std::string &filename) {
    std::ifstream myfile(filename);
    std::string line;
    if (myfile.is_open())
    {
        while(getline(myfile,line)) {
            input = line;
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";

    return line;
}

int HighScore::getScore() {
    return std::atoi(input.c_str());
}

void HighScore::setScore(int scoreIn) {
    std::string str1 = std::to_string(scoreIn);
    input = str1;
    text.setString("High Score: " + input);
}

void HighScore::setScoreFile() {
    std::ofstream myfile ("HighScore.txt");
    if (myfile.is_open()) {
        std::cout<<"setScoreFile: " << input << std::endl;
        myfile << input;
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
}

bool HighScore::load(const std::string& filename) {
    std::ifstream myfile (filename);
    std::string line;
    if (myfile.is_open())
    {
        while(getline(myfile,line)) {
            input = line;
            text.setString("High Score: " + input);
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";

    return true;
}

void HighScore::draw(sf::RenderWindow& window) {
    window.draw(text);
}

void HighScore::print() {
    sf::String str;
    std::string str1;
    str = text.getString();
    str1 = str.toAnsiString();
    //std::cout<< "print: " << str1 <<std::endl;
}

