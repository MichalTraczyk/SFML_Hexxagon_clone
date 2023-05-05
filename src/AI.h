//
// Created by Michał on 03.05.2023.
//

#ifndef HEXXAGON_AI_H
#define HEXXAGON_AI_H


#include "Move.h"
#include "Board/Board.h"

class AI {
public:
    static void makeBestMove(Board &board);
private:
    static int calculateMoveValue(Move &m, Board &board);
};


#endif //HEXXAGON_AI_H
