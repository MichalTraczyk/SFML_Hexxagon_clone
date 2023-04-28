//
// Created by Michaś on 28.04.2023.
//
#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H


#include <SFML/Graphics.hpp>
#include "Hex.h"
#include "../Owner.h"
class Board
{
public:
    Board(sf::RenderWindow &w);
    void drawHex(Hex& h);

private:
    const int radius = 50;

    sf::RenderWindow &window;
};
#endif //HEXXAGON_BOARD_H
