//
// Created by Michaś on 28.04.2023.
//

#include "Hex.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Owner.h"
#include "cmath"

Hex::Hex(int posX, int posY, const int &radius, Owner owner):positionX(posX),positionY(posY), owner(owner) {
    calculateCoordinates(radius);
}

void Hex::setPosY(int newPosY) {
    positionY = newPosY;
}
void Hex::setPosX(int newPosX) {
    positionX = newPosX;
}

int Hex::getPosX() {
    return positionX;
}
int Hex::getPosY() {
    return positionY;
}

Owner Hex::getOwner() {
    return owner;
}
void Hex::calculateCoordinates(const int &radius)
{
    float xDistance = radius*2;
    float yDistance = radius * sqrt(3) / 2;
    float offsetX = xDistance/5;;
    float offsetY = 0;
    if(positionX>4)
    {
        offsetY += yDistance*(positionX-4);
    }
    else if(positionX<4)
    {
        offsetY += yDistance*(4-positionX);
    }

    windowXPosition = (positionX+1) * xDistance + offsetX*(9-positionX);
    windowYPosition = (positionY+1)*2 * yDistance+offsetY;
}

sf::Vector2<int> Hex::getWindowPosition()
{
    return sf::Vector2(windowXPosition,windowYPosition);
}

void Hex::Move(sf::Vector2<int> move)
{
    windowXPosition+=move.x;
    windowYPosition+=move.y;
}
