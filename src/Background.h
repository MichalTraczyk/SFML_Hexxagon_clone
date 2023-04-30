//
// Created by Michał on 30.04.2023.
//

#ifndef HEXXAGON_BACKGROUND_H
#define HEXXAGON_BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background{
public:
    Background(sf::RenderWindow &window);
    void drawBackground();
private:
    sf::Clock clock;

    sf::RenderWindow window;
    std::vector<sf::CircleShape*> stars;
    int starsCount = 5;
    int maxSize = 5;
    int minSize = 10;
    int minSpeed = 50;
    int maxSpeed = 200;
};


#endif //HEXXAGON_BACKGROUND_H
