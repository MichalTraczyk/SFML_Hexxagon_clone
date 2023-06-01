//
// Created by Michał on 02.05.2023.
//

#ifndef HEXXAGON_MOVE_H
#define HEXXAGON_MOVE_H


#include "Board/Hex/Hex.h"
/**
 * @brief container class of values containing info about move
*/
class Move
{
public:
    /**
     * @brief Class constructor
     * @param from hex from we are moving
     * @param where hex where we are moving
     * @param duplicate if hex is going to be duplicated or just move
    */
    Move(Hex &from, Hex &where, bool duplicate);
    /**
     * @brief Coping constructor
    */
    Move(const Move &other);

    Hex &where;
    Hex &from;
    bool duplicate;

};


#endif //HEXXAGON_MOVE_H
