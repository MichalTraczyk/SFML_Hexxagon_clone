//
// Created by Michaś on 28.04.2023.
//

#include "Hex.h"
#include "../Owner.h"
Hex::Hex(int posX, int posY, Owner owner):positionX(posX),positionY(posY), owner(owner) {

}

void Hex::setPosY(int newPosY) {
    positionY = newPosY;
}
void Hex::setPosX(int newPosX) {
    positionX = newPosX;
}

Owner Hex::getOwner() {
    return owner;
}

