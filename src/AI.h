//
// Created by Michał on 03.05.2023.
//

#ifndef HEXXAGON_AI_H
#define HEXXAGON_AI_H


#include "Move.h"
#include "Board/Board.h"

/**
* @brief Class that calculates and makes moves as an AI
*/
class AI {
public:
    /**
    * @brief Makes best move for PLAYER2
     * @param board board where we should make best move
    */
    static void makeBestMove(Board &board);
private:
    /**
    * @brief Calculates value of given move on given board
     * @param m Move to make
     * @param board Board where move should be done
    */
    static int calculateMoveValue(Move &m, Board &board);
};


#endif //HEXXAGON_AI_H
