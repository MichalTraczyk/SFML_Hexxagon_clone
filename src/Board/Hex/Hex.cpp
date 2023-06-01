//
// Created by Michaś on 28.04.2023.
//

#include "Hex.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Owner.h"
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
    float offsetX = xDistance/((radius*1.0f)/8.0f);;
    offsetX+=5.0f;
    float offsetY = 0;
    if(positionX>4)
    {
        offsetY += (yDistance+2.5f)*(positionX-4);
    }
    else if(positionX<4)
    {
        offsetY += (yDistance+2.5f)*(4-positionX);
    }
    windowXPosition = (positionX+1) * xDistance + offsetX*(9-positionX);
    windowYPosition = (positionY+1)*2 * yDistance+offsetY + (5 * positionY);
}

sf::Vector2<int> Hex::getWindowPosition()
{
    return sf::Vector2(windowXPosition,windowYPosition);
}

void Hex::Move(sf::Vector2<int> move)
{
    shape.move(move.x,move.y);
    outline.move(move.x,move.y);
    selectObject.move(move.x,move.y);
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
    sf::Color color = sf::Color(200,0,167);
    sf::Color outlineColor = sf::Color(140,0,107);

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

    shape.setFillColor(color);

    outline.setFillColor(sf::Color(140,0,107));

    window.draw(outline);
    window.draw(shape);
}
void Hex::drawOutline()
{
    sf::Color outlineColor = sf::Color(140,0,107);
    switch (getState()) {
        case HexState::SELECTED: outlineColor = sf::Color::Yellow; break;
        case HexState::VERY_CLOSE: outlineColor = sf::Color::Green; break;
        case HexState::CLOSE: outlineColor = sf::Color::Yellow;  break;
        case HexState::NOTHING: outlineColor = sf::Color::Transparent; break;
    }

    selectObject.setOutlineColor(outlineColor);

    window.draw(selectObject);
}
void Hex::generateShape()
{
    shape = sf::ConvexShape();
    shape.setPosition(windowXPosition, windowYPosition);
    shape.setPointCount(6);

    for(int i = 0;i<6;i++)
    {
        float angle_deg = 60*i;
        float angle_rad = 3.1415 / 180 * angle_deg;
        //float px = h.getPosX() + radius*cos(angle_rad);
        float px = (radius-5)*cos(angle_rad);
        //float py = h.getPosY() + radius* sin(angle_rad);
        float py = (radius-5)*sin(angle_rad);
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
        float px = (radius+3)*cos(angle_rad);
        //float py = h.getPosY() + radius* sin(angle_rad);
        float py = (radius+3)* sin(angle_rad);
        outline.setPoint(i, sf::Vector2f(px, py));
    }
    outline.setFillColor(sf::Color::Yellow);


    selectObject = sf::ConvexShape();
    selectObject.setPosition(windowXPosition, windowYPosition);
    selectObject.setPointCount(6);

    for(int i = 0;i<6;i++)
    {
        float angle_deg = 60*i;
        float angle_rad = 3.1415 / 180 * angle_deg;
        //float px = h.getPosX() + radius*cos(angle_rad);
        float px = (radius-3)*cos(angle_rad);
        //float py = h.getPosY() + radius* sin(angle_rad);
        float py = (radius-3)* sin(angle_rad);
        selectObject.setPoint(i, sf::Vector2f(px, py));
    }
    selectObject.setFillColor(sf::Color::Transparent);
    selectObject.setOutlineColor(sf::Color::Transparent);
    selectObject.setOutlineThickness(4);
}

bool Hex::contains(sf::Vector2<float> pos)
{
    int x = abs(pos.x-windowXPosition);
    int y = abs(pos.y-windowYPosition);

    float c = x*x + y*y;
    c = sqrt(c);

    float h = radius * 1.73 /2;
    return c<h;
}

Hex::~Hex()
{
    std::cout<<"HEX DECONSTURCOT"<<std::endl;
    //delete this;
}
