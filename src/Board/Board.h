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
    void drawBoard();
private:

    sf::Font font;
    void buildBoard();
    void drawHex(Hex& h);
    void offsetHexes();
    std::vector<std::vector<Hex>> boardState={
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {}
    };
    const int radius = 50;

    sf::RenderWindow &window;
};
#endif //HEXXAGON_BOARD_H
