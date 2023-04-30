//
// Created by Michaś on 28.04.2023.
//

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cmath"
#include "Hex.h"
#include "vector"

Board::Board(sf::RenderWindow &w) : window(w)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    //Creates vector of hexes
    buildBoard();

    //Offsets hexes so the board is in the middle
    offsetHexes();

    //Draws every hex according to its state and position
    drawBoard();
}

void Board::drawBoard() {

    for(int i = 0; i<boardState.size(); i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            drawHex(boardState[i][j]);
        }
    }
}

void Board::drawHex(Hex& h)
{
    sf::ConvexShape shape;

    sf::Color color = sf::Color::Magenta;
    switch (h.getOwner())
    {
        case Owner::NO_ONE:
            color = sf::Color::Yellow;
            break;
        case Owner::PLAYER1:
            color = sf::Color::Green;
            break;
        case Owner::PLAYER2:
            color = sf::Color::Cyan;
            break;
    }
    shape.setFillColor(color);

    shape.setPosition(h.getWindowPosition().x, h.getWindowPosition().y);
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
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(3);

    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    std::string t = std::to_string(h.getPosX()) + " " + std::to_string(h.getPosY());
    text.setString(t);

    text.setPosition(h.getWindowPosition().x,h.getWindowPosition().y);
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // inside the main loop, between window.clear() and window.display()

    window.draw(shape);
    window.draw(text);
}

void Board::buildBoard()
{
    for(int i = 0;i<5;i++)
    {
        for (int j = 0; j<i+5;j++)
        {
            boardState[i].push_back(Hex(i,j,radius,Owner::NO_ONE));
        }
    }
    for (int i = 0; i<4;i++)
    {
        for(int j = 0; j<8-i;j++)
        {
            boardState[i+5].push_back(Hex(i+5,j,radius,Owner::NO_ONE));
        }
    }
}

void Board::offsetHexes()
{
    int xSize = window.getSize().x;
    int boardSize = boardState[8][0].getWindowPosition().x - boardState[0][0].getWindowPosition().x;
    int remainingSize = xSize - boardSize;

    int distance = boardState[0][0].getWindowPosition().x;
    int moveDistance = remainingSize/2 - distance;


    for (int i = 0; i < boardState.size(); i++)
    {
        for (int j = 0;j<boardState[i].size();j++)
        {
            boardState[i][j].Move(sf::Vector2<int>(moveDistance,0));
        }
    }
}

