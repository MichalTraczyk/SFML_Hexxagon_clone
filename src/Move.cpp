//
// Created by Michał on 02.05.2023.
//

#include <iostream>
#include "Move.h"

Move::Move(Hex &from, Hex &where, bool duplicate): from(from), where(where), duplicate(duplicate){

}

Move::Move(const Move &other) : from(other.from), where(other.where), duplicate(other.duplicate)
{
    std::cout<<"copy!"<<std::endl;
}
