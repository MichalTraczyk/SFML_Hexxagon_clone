//
// Created by Michaś on 28.04.2023.
//
#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H


#include <SFML/Graphics.hpp>
#include "Hex.h"
#include "../Owner.h"
#include "../Move.h"

class Board
{
public:
    Board(sf::RenderWindow &w, bool againstAI);
    void drawBoard();
    void OnMouseClicked(sf::Vector2<int> position);
    std::vector<std::vector<Hex>> * getBoardState();
    std::map<Hex *, HexState> findPossibleMoves(Hex &h);
    std::map<Hex *, int> findCloseHexes(Hex &h);
    void Update();

private:
    bool againstAI;
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

    void resetHexesState();
    void move(Move &move);

    //void move(Move m);
    void AIMove();
    sf::Clock clock;
    float aiMoveTimer;
};
#endif //HEXXAGON_BOARD_H
