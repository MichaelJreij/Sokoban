// Copyright 2023 <Michael Jreij>"
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Sokoban : public sf::Drawable {
 private:
int playerI;
int playerJ;
std::vector<int> storagePos {};
std::vector<bool> occupied{};
    const std::string level;
    std::vector<std::vector<char>> gameBoard;
    int widthL;
    int heightL;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture wall;
    sf::Texture crate;
    sf::Texture groundEmpty;
    sf::Texture ground;
    sf::Texture player;

 public:
    Sokoban();  // default constructor
    Sokoban(int player);

    void loadLevel(std::string fileName);

     int width() const;
     int height() const;
     int isWon() const;
     int movePlayer(int x, int y);
};
