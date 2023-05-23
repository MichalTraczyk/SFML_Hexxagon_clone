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
    const static int maxSavedGames = 6;
    static bool doesSavesExist(int saveNumber);

    //saving and loading saves
    static std::vector<HexInfo*> getBoardStateFromSave(int save);
    static void saveBoardstate(const std::vector<std::vector<Hex*>> &boardState, const Owner &playerTurn,const int &save);


    static void trySaveNewHighscore(const int &newHighscore,const Owner &owner);
private:
    static void saveHexInfoToFile(std::vector<HexInfo> &infos,std::string file);
};


#endif //HEXXAGON_GAMESAVER_H
