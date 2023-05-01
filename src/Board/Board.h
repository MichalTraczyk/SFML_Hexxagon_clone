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
    void OnMouseClicked(sf::Vector2<int> position);

private:

    Owner currentPlayerTurn = Owner::PLAYER1;
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

    Hex* selectedHex= nullptr;
    sf::RenderWindow &window;

    void selectHex(Hex &h);
    std::map<Hex *, int> findCloseHexes(Hex &h);

    void move(Hex &from, Hex &where, bool duplicate);

    void resetHexesState();
};
#endif //HEXXAGON_BOARD_H
