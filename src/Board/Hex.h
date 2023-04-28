//
// Created by Michaś on 28.04.2023.
//

#ifndef HEXXAGON_HEX_H
#define HEXXAGON_HEX_H

#include <SFML/Graphics.hpp>
#include "../Owner.h"
class Hex
{
public:
    Hex(int posX,int posY, const int &radius, Owner owner = Owner::PLAYER1);

    int getPosX();
    int getPosY();

    void setPosY(int newPosY);
    void setPosX(int newPosX);

    void Move(sf::Vector2<int> move);
    sf::Vector2<int> getWindowPosition();

    Owner getOwner();

private:
    int positionX;
    int positionY;

    int windowXPosition;
    int windowYPosition;

    void calculateCoordinates(const int &radius);
    Owner owner;
};


#endif //HEXXAGON_HEX_H
