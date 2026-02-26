// Copyright 2023 <Michael Jreij>"
#include "Sokoban.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>

Sokoban::Sokoban() {  // default constructor
}


Sokoban::Sokoban(int player) {
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Sprite s;
    sf::Sprite previous;
    for (int i = 0; i <height(); i ++) {
        for (int j = 0; j < width(); j++) {
            if (gameBoard[i][j] =='#')
            s.setTexture(wall);
            if (gameBoard[i][j] =='A')
            s.setTexture(crate);
            if (gameBoard[i][j] =='a')
            s.setTexture(groundEmpty);
            if (gameBoard[i][j] =='@') {
            s.setTexture(player);
            previous.setPosition(j*64, i*64);
            previous.setTexture(ground);
            target.draw(previous);
            }
            if (gameBoard[i][j] =='.')
            s.setTexture(ground);

            s.setPosition(j * 64, i * 64);
            target.draw(s);
        }
    }
}

void Sokoban::loadLevel(std::string fileName) {
    wall.loadFromFile("block_06.png");
    crate.loadFromFile("crate_03.png");
    groundEmpty.loadFromFile("ground_04.png");
    ground.loadFromFile("ground_01.png");
    player.loadFromFile("player_05.png");



    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
}
    file >> heightL >> widthL;
    std::cout << "Width: " << widthL << ", Height: " << heightL << std::endl;
      // test the height/width methods

    file >> std::ws;

     std::string line;
    for (int i = 0; i < heightL; i++) {
        std::vector <char> v1;
        for (int j = 0; j < widthL; j++) {
            char c;
            file >> c;
            v1.push_back(c);
        }
        gameBoard.push_back(v1);
    }

    for (int i = 0; i < heightL; i++) {
        for (int j = 0; j < widthL; j++) {
            std::cout << gameBoard[i][j];
            if (gameBoard[i][j] == '@') {
            playerI = i;
            playerJ = j;
            }
            if (gameBoard[i][j] == 'a') {
            storagePos.push_back(i);
            storagePos.push_back(j);
            }
        }
        std::cout << std::endl;
    }
}

int Sokoban::width() const {
    return widthL;
}

int Sokoban::height() const {
    return heightL;
}

int Sokoban::isWon() const {
    return 0;
}

int Sokoban::movePlayer(int x, int y) {
    if (gameBoard[playerI+x][playerJ+y] == '#') {
        return 0;
    } else if (gameBoard[playerI+x][playerJ+y] == 'a') {
} else if (gameBoard[playerI+x][playerJ+y] == 'A'
&& gameBoard[playerI+x+x][playerJ+y+y] == '#') {
        return 0;
    } else if (gameBoard[playerI+x][playerJ+y] == 'A') {
        gameBoard[playerI+x+x][playerJ+y+y] = 'A';
    }

    gameBoard[playerI+x][playerJ+y] = gameBoard[playerI][playerJ];
    gameBoard[playerI][playerJ] = '.';

    playerI += x;
    playerJ += y;

     return 0;
}
// ./Sokoban level1.lvl
