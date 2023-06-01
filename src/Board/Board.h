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
class GameManager;
#include "../GameManager.h"

/**
 * @brief class that handles game logic
*/
class Board
{
public:

    /**
     * @brief class constructor
     *
     * @param w Window where everything should be drawn
     * @param againstAI Decision if AI should control player 2
     * @param gm Master game manager
     * @param save save index which should be used, -1 means create new save
    */
    Board(sf::RenderWindow &w, bool againstAI,GameManager* gm,const int &save);

    /**
     * @brief draws everything related to board on the screen
    */
    void drawBoard();
    /**
     * @brief Invoked when left mouse button is clicked
     * @param position Position of cursor
    */
    void OnMouseClicked(sf::Vector2<float> position);

    /**
     * @brief returns current boardstate
     * @return vector of vectors of Hexes
    */
    std::vector<std::vector<Hex *>> * getBoardState();

    /**
     * @brief returns map of close and empty hexes, and their distance from parameter
     * @param h Hex for which we want to calculate moves
     * @return map of key - hex, value - distance from origin
    */
    std::map<Hex *, HexState> findPossibleMoves(Hex &h);

    /**
     * @brief returns map of close hexes, and their distance from parameter
     * @param h Hex for which we want to calculate distance
     * @return map of key - hex, value - distance from origin
    */
    std::map<Hex *, int> findCloseHexes(Hex &h);

    /**
     * @brief void called every frame
     * @param deltaTime time since last frame
    */
    void Update(float deltaTime);

    /**
     * @brief makes move on current boardstate
     * @param move move declaration
    */
    void move(Move &move);

    /**
     * @brief returns current player turn
     * @return Owner enum of current player turn
    */
    Owner getCurrentPlayerTurn();

    /**
     * @brief called when current player cant make a move, so when the game ends
    */
    void onNoMoreMoves();

    /**
     * @brief returns scores of each player
     * x param - Player1 score
     * y param - Player2 score
     * @return vector of two scores
    */
    sf::Vector2<int> getScores();

private:
    sf::RenderWindow &window;
    //Scoreboard
    Scoreboard* scoreboard;
    GameManager* gameManager;

    //Ai
    bool againstAI;
    /**
    * @brief make AI move as Player2
    */
    void AIMove();
    float aiMoveTimer;


    //Game logic
    Owner currentPlayerTurn = Owner::PLAYER1;
    /**
    * @brief create new boardstaet basing on save
     * @param save save to refer
    */
    void buildBoard(const int &save);

    std::vector<std::vector<Hex*>> boardState={
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
    /**
    * @brief draws hex and his outline
     * @param h hex to draw
    */
    void drawHex(Hex& h);
    const int radius = 50;
    /**
    * @brief offsets every hex so board is in the middle of the window
    */
    void offsetHexes();


    //Movement
    /**
    * @brief Selects hex and calculates possible moves
     * @param h Hex to select
    */
    void selectHex(Hex &h);
    /**
    * @brief Unselects all hexes
    */
    void unselectAllHexes();

    /**
    * @brief Fills every empty hex
     * Called when someone can't move
     * @param toFill New owner of empty hexes
    */
    void fillEmptyHexes(Owner toFill);

    /**
    * @brief Checks if player can move
     * @param player player to check
     * @return boolean if player can make any move
    */
    bool CanMove(Owner player);
};
#endif //HEXXAGON_BOARD_H
