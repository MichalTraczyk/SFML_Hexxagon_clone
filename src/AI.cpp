//
// Created by Michał on 03.05.2023.
//

#include <iostream>
#include "AI.h"
int AI::calculateMoveValue(Move &m, Board &board)
{
    int val = m.duplicate;

    auto hexes = board.findCloseHexes(m.where);
    for(auto i : hexes)
    {
        if(i.first->getOwner()==Owner::PLAYER1 && i.second <= 2)
        {
            val++;
        }
    }
    return val;
}
void AI::makeBestMove(Board &board) {


    std::vector<std::vector<Hex>> boardState = *board.getBoardState();
    int maxVal = 0;
    Move* bestMove = nullptr;

    for (int i = 0; i<boardState.size(); i++)
    {
        for (int j = 0; j<boardState[i].size(); j++)
        {
            if(boardState[i][j].getOwner() != Owner::PLAYER2)
                continue;
            auto mapa = board.findPossibleMoves(boardState[i][j]);
            for(auto k : mapa)
            {
                bool dup = k.second == HexState::VERY_CLOSE;
                Move m = Move(boardState[i][j],*k.first,dup);

                int val = calculateMoveValue(m,board);
                if(val > maxVal)
                {
                    Move newBest = Move(boardState[i][j],*k.first,dup);
                    bestMove = &newBest;
                }
            }
        }
    }
/*    std::cout<<"============: "<<std::endl;
    std::cout<<"from: " << from->getPosX() << " " << from->getPosY() << std::endl;
    std::cout<<"to: " << where->getPosX() << " " << where->getPosY() << std::endl;
    std::cout<<"addres from: "<<from<< std::endl;
    std::cout<<"addres where : "<<where<< std::endl;*/
    board.move(*bestMove);
}
