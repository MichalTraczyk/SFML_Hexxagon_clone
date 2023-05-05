//
// Created by Michał on 02.05.2023.
//

#ifndef HEXXAGON_MOVE_H
#define HEXXAGON_MOVE_H


#include "Board/Hex.h"

class Move
{
public:
    Move(Hex &from, Hex &where, bool duplicate);
    Move(const Move &other);
    Hex &where;
    Hex &from;
    bool duplicate;

};


#endif //HEXXAGON_MOVE_H
