//
// Created by Michaś on 28.04.2023.
//
#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H


#include <SFML/Graphics.hpp>
#include "Hex/Hex.h"
#include "../Owner.h"
#include "../Move.h"
#include "Scoreboard.h"

class Board
{
public:
    Board(sf::RenderWindow &w, bool againstAI);
    void drawBoard();
    void OnMouseClicked(sf::Vector2<int> position);
    std::vector<std::vector<Hex>> * getBoardState();
    std::map<Hex *, HexState> findPossibleMoves(Hex &h);
    std::map<Hex *, int> findCloseHexes(Hex &h);
    void Update(float deltaTime);
    void move(Move &move);

private:
    sf::RenderWindow &window;

    //Scoreboard
    Scoreboard* scoreboard;

    //Ai
    bool againstAI;
    void AIMove();
    float aiMoveTimer;


    //Game logic
    Owner currentPlayerTurn = Owner::PLAYER1;
    void buildBoard();
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
    Hex* selectedHex= nullptr;


    //visuals
    sf::Font font;
    void drawHex(Hex& h);
    const int radius = 50;
    void offsetHexes();


    //Movement
    void selectHex(Hex &h);
    void unselectAllHexes();

};
#endif //HEXXAGON_BOARD_H
