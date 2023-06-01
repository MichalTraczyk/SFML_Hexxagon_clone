//
// Created by Michał on 01.05.2023.
//

#ifndef HEXXAGON_STAR_H
#define HEXXAGON_STAR_H

#include <SFML/Graphics.hpp>
class Star{

public:
    Star();
    /**
    * @brief Moves the star
    *
    * @param deltaTime Time since last frame to move stars with the fixed speed.
    */
    void move(float deltaTime);

    /**
    * @brief Moves the star
    *
    * @return Returns the shape of the star
    */
    sf::CircleShape* getShape();

    /**
    * @brief sets new parameters for star
    *
    * @param newSize New size of the star
    * @param newSpeed New moving speed of the star
    * @param pos New position of the star
    */
    void reset(int newSize, int newSpeed,sf::Vector2<int> pos);
private:
    int speed;
    sf::CircleShape shape;
};


#endif //HEXXAGON_STAR_H
