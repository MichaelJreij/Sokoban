// Copyright 2023 <Michael Jreij>"
#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"

int main(int argc, char *argv[]) {
  std::string fileName = argv[1];
  Sokoban sokoban;
  sokoban.loadLevel(fileName);

  sf::RenderWindow window(sf::VideoMode(sokoban.width() * 64,
                                       sokoban.height() * 64),
                        "SFML window");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A || event.key.code ==
        sf::Keyboard::Left) {
            sokoban.movePlayer(0, -1);
          std::cout << "A \n";
        } else if (event.key.code == sf::Keyboard::W || event.key.code ==
        sf::Keyboard::Up) {
            sokoban.movePlayer(-1, 0);
          std::cout << "W \n";
        } else if (event.key.code == sf::Keyboard::S || event.key.code ==
        sf::Keyboard::Down) {
            sokoban.movePlayer(1, 0);
          std::cout << "S \n";
        } else if (event.key.code == sf::Keyboard::D || event.key.code ==
        sf::Keyboard::Right) {
            sokoban.movePlayer(0, 1);
          std::cout << "D \n";
        }
      }
    }

    window.draw(sokoban);
    window.display();
  }

  return 0;
}
