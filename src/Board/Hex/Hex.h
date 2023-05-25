//
// Created by Michaś on 28.04.2023.
//

#ifndef HEXXAGON_HEX_H
#define HEXXAGON_HEX_H

#include <SFML/Graphics.hpp>
#include "../../Owner.h"
#include "HexState.h"
class Hex
{
public:
    ~Hex();
    Hex(int posX,int posY, const int &radius,sf::RenderWindow &window,Owner owner = Owner::PLAYER1);

    int getPosX();
    int getPosY();

    void Move(sf::Vector2<int> move);
    sf::Vector2<int> getWindowPosition();

    Owner getOwner();
    void setOwner(Owner owner);

    void select();
    void unselect();

    bool contains(sf::Vector2<float> pos);
    HexState getState();

    void drawHex();

    HexState setState(HexState newState);

    void drawOutline();

private:

    int positionX;
    int positionY;
    int windowXPosition;
    int windowYPosition;
    int radius;


    void generateShape();

    sf::ConvexShape shape;
    sf::ConvexShape outline;
    sf::ConvexShape selectObject;

    void calculateCoordinates(const int &radius);
    sf::RenderWindow &window;
    Owner owner;
    HexState state;

};


#endif //HEXXAGON_HEX_H
