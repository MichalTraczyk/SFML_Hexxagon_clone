//
// Created by Michał on 22.05.2023.
//

#ifndef HEXXAGON_GAMESAVER_H
#define HEXXAGON_GAMESAVER_H


#include <vector>
#include "Board/Hex/Hex.h"
struct HexInfo
{
    HexInfo(int i, int j, Owner owner);
    int posx;
    int posy;
    Owner owner;
};

class GameSaver
{
public:
    static std::vector<HexInfo*> getBoardStateFromSave(int save);
    static void saveBoardstate(const std::vector<std::vector<Hex*>> &boardState, const Owner &playerTurn);
    static void trySaveNewHighscore(const int &newHighscore,const Owner &owner);

private:

    static std::vector<HexInfo*> buildEmptyBoard();
    static void saveHexInfoToFile(std::vector<HexInfo> &infos,std::string file);
    static int getNumberOfSavedGames();
};


#endif //HEXXAGON_GAMESAVER_H
