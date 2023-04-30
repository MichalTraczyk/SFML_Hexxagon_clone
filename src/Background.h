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
    std::vector<sf::ConvexShape> stars;
    int starsCount;
    float maxSize = 5;
    float minSize = 10;
    float minSpeed = 50;
    float maxSpeed = 200;
};


#endif //HEXXAGON_BACKGROUND_H
