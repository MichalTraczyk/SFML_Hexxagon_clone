//
// Created by Michał on 30.04.2023.
//

#ifndef HEXXAGON_BACKGROUND_H
#define HEXXAGON_BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "Star.h"

class Background{
public:
    Background(sf::RenderWindow &window);
    void drawBackground(float deltaTime);
    void moveStars(float deltaTime);
private:
    sf::Clock clock;

    void setupStar(Star &s, bool startSetup = false);
    sf::RenderWindow &window;
    std::vector<Star> stars;
    int starsCount = 70;
    int maxSize = 10;
    int minSize = 2;
    int minSpeed = 100;
    int maxSpeed = 50;
    sf::CircleShape shape;
};


#endif //HEXXAGON_BACKGROUND_H
