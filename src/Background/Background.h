//
// Created by Michał on 30.04.2023.
//

#ifndef HEXXAGON_BACKGROUND_H
#define HEXXAGON_BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "Star.h"
/**
 * @brief Controls the background stars.
 *
 * This class controls the behaviour of stars that float in the backgroud
 *
 */
class Background{
public:
    /**
    * @brief Constructor of the class
    *
    * @param window Window where background should be drawn.
    */
    Background(sf::RenderWindow &window);

    /**
    * @brief Draws every star
    *
    * @param deltaTime Time since last frame to move stars with the fixed speed.
    */
    void drawBackground(float deltaTime);

    /**
    * @brief moves every star
    *
    * @param deltaTime Time since last frame to move stars with the fixed speed.
    */
    void moveStars(float deltaTime);
private:
    sf::Clock clock;

    /**
    * @brief Setups the star when it gets to the end of the screen
    *
    * @param s Star which we want to setup.
    * @param startSetup Boolean that decides if we should spawn star in the middle of screen or beggining.
    */
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
