//
// Created by Michał on 01.05.2023.
//

#ifndef HEXXAGON_STAR_H
#define HEXXAGON_STAR_H

#include <SFML/Graphics.hpp>
class Star{

public:
    Star();
    void move(float deltaTime);
    sf::CircleShape* getShape();
    void reset(int newSize, int newSpeed,sf::Vector2<int> pos);
private:
    int speed;
    sf::CircleShape shape;
};


#endif //HEXXAGON_STAR_H
