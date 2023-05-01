//
// Created by Michał on 01.05.2023.
//

#include "Star.h"

void Star::move(float deltaTime)
{
    shape.move(-speed*deltaTime,0);
}

void Star::reset(int newSize, int newSpeed,sf::Vector2<int> pos)
{
    shape = sf::CircleShape();
    shape.setRadius(newSize);
    speed = newSpeed;
    shape.setPosition(pos.x,pos.y);
}
sf::CircleShape* Star::getShape()
{
    return &shape;
}
Star::Star() {
}
