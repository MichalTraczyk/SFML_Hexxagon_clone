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
    void move(Move &move);

private:

    sf::RenderWindow &window;
    sf::Clock clock;

    //Scoreboard
    int player1Score = 0;
    int player2Score = 0;

    const int scoreBoardDownDistance = 100;
    const int scoreBoardRightDistance = 500;

    const int scoreboardRectHeight = 35;
    const int scoreboardRectWidthMultiplier = 10;

    sf::RectangleShape player1PointsRect;
    sf::RectangleShape player2PointsRect;

    sf::Text player1PointsText;
    sf::Text player2PointsText;

    void buildScoreboard();
    void drawScoreboard();
    void recalculatePoints();
    void calculateScoreboard();

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
