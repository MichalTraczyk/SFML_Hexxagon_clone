//
// Created by Michaś on 28.04.2023.
//

#ifndef HEXXAGON_HEX_H
#define HEXXAGON_HEX_H

#include "../Owner.h"
class Hex
{
public:
    Hex(int posX,int posY, Owner owner = Owner::PLAYER1);

    int positionX;
    int positionY;

    Owner getOwner();

private:
    Owner owner;
    void setPosY(int newPosY);
    void setPosX(int newPosX);
};


#endif //HEXXAGON_HEX_H
