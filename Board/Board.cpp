//
// Created by Michaś on 28.04.2023.
//

#include "Board.h"
#include <SFML/Graphics.hpp>
#include "cmath"
#include "Hex.h"
#include "../Owner.h"

Board::Board(sf::RenderWindow &w) : window(w)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.clear();
    window.draw(shape);
    window.display();
}

void Board::drawHex(Hex& h)
{
    sf::ConvexShape shape;

    sf::Color color = sf::Color::Magenta;
    switch (h.getOwner())
    {
        case Owner::NO_ONE:
            color = sf::Color::White;
            break;
        case Owner::PLAYER1:
            color = sf::Color::Green;
            break;
        case Owner::PLAYER2:
            color = sf::Color::Cyan;
            break;
    }
    shape.setFillColor(color);
    float add = 0;
    if(h.positionY%2==0)
    {
        add = 0.5f;
    }

    float xDistance = radius* sqrt(3);
    float yDistance = 1.5 * radius;

    shape.setPosition((h.positionX + add) * xDistance, h.positionY * yDistance);
    shape.setPointCount(6);

    for(int i = 0;i<6;i++)
    {
        float angle_deg = 60*i+30;
        float angle_rad = 3.1415 / 180 * angle_deg;
        float px = h.positionX + radius*cos(angle_rad);
        float py = h.positionY + radius* sin(angle_rad);
        shape.setPoint(i, sf::Vector2f(px, py));
    }
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(3);
    window.draw(shape);
}

