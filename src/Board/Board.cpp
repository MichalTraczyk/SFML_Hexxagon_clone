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
void Board::OnMouseClicked(sf::Vector2<int> position)
{
    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            if(boardState[i][j].contains(position))
            {
                if( boardState[i][j].getOwner() == currentPlayerTurn)
                    selectHex(boardState[i][j]);
                else if(boardState[i][j].getState() == HexState::CLOSE)
                {
                    move(*selectedHex, boardState[i][j], false);
                }
                else if(boardState[i][j].getState() == HexState::VERY_CLOSE)
                {
                    move(*selectedHex, boardState[i][j], true);
                }
            }
        }
    }
}
void Board::move(Hex &from, Hex &where, bool duplicate)
{
    where.setOwner(from.getOwner());

    if(!duplicate)
    {
        from.setOwner(Owner::NO_ONE);
    }
    resetHexesState();
    for(auto i : findCloseHexes(where))
    {
        if(i.first->getOwner() != Owner::NO_ONE && i.first->getOwner() != where.getOwner() && i.second <= 2)
        {
            i.first->setOwner(where.getOwner());
        }
    }
    if(currentPlayerTurn==Owner::PLAYER1)
        currentPlayerTurn = Owner::PLAYER2;
    else
        currentPlayerTurn = Owner::PLAYER1;
}
void Board::resetHexesState()
{
    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            boardState[i][j].setState(HexState::NOTHING);
        }
    }
}
void Board::selectHex(Hex &h)
{
    if(selectedHex != nullptr)
        selectedHex->unselect();

    selectedHex = &h;
    h.select();

    auto mapa = findCloseHexes(h);;
    for(auto i : mapa)
    {
        if(i.first->getOwner() != Owner::NO_ONE)
            continue;
        if(i.second<=4 && i.second >= 2)
            i.first->setState(HexState::CLOSE);
        else if(i.second <= 2)
            i.first->setState(HexState::VERY_CLOSE);
    }
}


float distance(int x1, int x2, int y1, int y2)
{
    int x = abs(x2-x1);
    int y = abs(y2-y1);

    float c = x*x + y*y;
    c = sqrt(c);

    return c;
}

std::map<Hex*,int> Board::findCloseHexes(Hex &h)
{
    auto mapa = std::map<Hex*,int>();
    mapa.clear();

    for (int i = 0; i < boardState.size(); ++i)
    {
        for (int j = 0; j < boardState[i].size(); ++j)
        {
            float d = distance(h.getWindowPosition().x,boardState[i][j].getWindowPosition().x,h.getWindowPosition().y,boardState[i][j].getWindowPosition().y);
            d/=radius;
            //boardState[i][j].distance = d;
            if(d<=4)
            {
                mapa[&boardState[i][j]] = (int)d;
            }
            else
            {
                boardState[i][j].setState(HexState::NOTHING);
            }
        }
    }
    return mapa;
}

void Board::drawHex(Hex& h)
{
    h.drawHex();
    h.drawOutline();
/*    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    //std::string t = std::to_string(h.getPosX()) + " " + std::to_string(h.getPosY());
    std::string t = std::to_string(h.distance);
*//*    std::string t = "";
    switch (h.getState())
    {
        case HexState::NOTHING: t = "NTH";break;
        case HexState::SELECTED: t = "SEL"; break;
        case HexState::CLOSE: t = "CL"; break;
        case HexState::VERY_CLOSE: t = "VC"; break;

    }*//*
    text.setString(t);

    text.setPosition(h.getWindowPosition().x,h.getWindowPosition().y);
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Black);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // inside the main loop, between window.clear() and window.display()

    window.draw(text);*/
}

void Board::buildBoard()
{
    for(int i = 0;i<5;i++)
    {
        for (int j = 0; j<i+5;j++)
        {
            if((i==4 && j==3) || (i == 3 && j == 4))
                continue;
            boardState[i].push_back(Hex(i,j,radius,window,Owner::NO_ONE));

        }
    }
    for (int i = 0; i<4;i++)
    {
        for(int j = 0; j<8-i;j++)
        {
            if(i==0 && j == 4)
                continue;
            boardState[i+5].push_back(Hex(i+5,j,radius,window,Owner::NO_ONE));
        }
    }


    boardState[0][0].setOwner(Owner::PLAYER1);
    boardState[0][4].setOwner(Owner::PLAYER2);

    boardState[4][0].setOwner(Owner::PLAYER2);
    boardState[4][7].setOwner(Owner::PLAYER1);

    boardState[8][0].setOwner(Owner::PLAYER1);
    boardState[8][4].setOwner(Owner::PLAYER2);
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

