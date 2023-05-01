//
// Created by Michaś on 28.04.2023.
//

#include "Hex.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Owner.h"
#include "cmath"

Hex::Hex(int posX, int posY, const int &radius,sf::RenderWindow &w,Owner owner):positionX(posX),window(w),positionY(posY),radius(radius), owner(owner)
{
    state = HexState::NOTHING;
    calculateCoordinates(radius);
    generateShape();
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
    shape.move(move.x,move.y);
    windowXPosition+=move.x;
    windowYPosition+=move.y;
}

void Hex::setOwner(Owner o)
{
    owner = o;
}

void Hex::select() {
    state = HexState::SELECTED;
}

void Hex::unselect() {
    state = HexState::NOTHING;
}

HexState Hex::getState() {
    return state;
}
HexState Hex::setState(HexState newState) {
    state = newState;
}
void Hex::drawHex()
{
    sf::Color color = sf::Color::Magenta;
    sf::Color outlineColor = sf::Color::Black;

    switch (getOwner())
    {
        case Owner::NO_ONE:
            color = sf::Color::Magenta;
            break;
        case Owner::PLAYER1:
            color = sf::Color::Green;
            break;
        case Owner::PLAYER2:
            color = sf::Color::Cyan;
            break;
    }


    switch (getState()) {
        case HexState::SELECTED: outlineColor = sf::Color::Yellow; break;
        case HexState::VERY_CLOSE: outlineColor = sf::Color::Green; break;
        case HexState::CLOSE: outlineColor = sf::Color::Yellow;  break;
    }


    shape.setFillColor(color);
    outline.setFillColor(outlineColor);

    std::cout<<outline.getPosition().x<<" "<<outline.getPosition().y<< std::endl;

    window.draw(shape);
    window.draw(outline);
}

void Hex::generateShape()
{
    shape = sf::ConvexShape();
    //shape.setOrigin(windowXPosition,windowYPosition);
    shape.setPosition(windowXPosition, windowYPosition);
    shape.setPointCount(6);

    for(int i = 0;i<6;i++)
    {
        float angle_deg = 60*i;
        float angle_rad = 3.1415 / 180 * angle_deg;
        //float px = h.getPosX() + radius*cos(angle_rad);
        float px = radius*cos(angle_rad);
        //float py = h.getPosY() + radius* sin(angle_rad);
        float py = radius* sin(angle_rad);
        shape.setPoint(i, sf::Vector2f(px, py));
    }
    shape.setFillColor(sf::Color::Yellow);



    outline = sf::ConvexShape();
    outline.setPosition(windowXPosition, windowYPosition);
    outline.setPointCount(6);

    for(int i = 0;i<6;i++)
    {
        float angle_deg = 60*i;
        float angle_rad = 3.1415 / 180 * angle_deg;
        //float px = h.getPosX() + radius*cos(angle_rad);
        float px = radius*(4/5)*cos(angle_rad);
        //float py = h.getPosY() + radius* sin(angle_rad);
        float py = radius*(4/5)* sin(angle_rad);
        outline.setPoint(i, sf::Vector2f(px, py));
    }
    outline.setFillColor(sf::Color::Yellow);

    //shape.setOutlineColor(sf::Color::White);
    //shape.setOutlineThickness(3);

}

bool Hex::contains(sf::Vector2<int> pos)
{
    sf::Vector2<float> l1 = shape.getPoint(2);
    sf::Vector2<float> l2 = shape.getPoint(5);

    l1 = shape.getTransform().transformPoint(l1);
    l2 = shape.getTransform().transformPoint(l2);

    if(pos.x >= l1.x && pos.x <= l2.x && pos.y >= l2.y && pos.y <= l1.y)
        return true;
    else
        return false;
/*    if(positionX == 0 && positionY == 0)
    {
        std::cout<<"pos: " << windowXPosition << " " << windowYPosition<<std::endl;
        std::cout<<"pos point: " << l1.x << " " << l1.y<<std::endl;
        std::cout<<"pos poin2t: " << l2.x << " " << l2.y<<std::endl;
    }
    return false;*/
}
