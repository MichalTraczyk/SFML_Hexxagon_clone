//
// Created by Michał on 22.05.2023.
//

#include "GameSaver.h"
#include <fstream>
#include <iostream>

bool GameSaver::doesSavesExist(int saveIndex)
{
    std::string fileName = "Saves/SaveFile" + std::to_string(saveIndex) + ".hex";
    auto file = std::fstream(fileName,std::ios::in | std::ios::app);
    int c=0;
    for(auto line = std::string() ; std::getline(file, line); )
    {
        c++;
        //if file is not empty
        if(c>1)
            return true;
    }
    return false;
}
std::vector<HexInfo*> GameSaver::getBoardStateFromSave(int save)
{
    std::vector<HexInfo*> hexInfos={};
    std::string fileName = "Saves/SaveFile" + std::to_string(save) + ".hex";

    auto file = std::fstream(fileName);
    for(auto line = std::string() ; std::getline(file, line); ){

        int posX = line[0]-48;
        int posY = line[2]-48;
        int own = line[4]-48;

        Owner o = Owner::NO_ONE;
        if(own==1)
            o=Owner::PLAYER1;
        else if(own==2)
            o=Owner::PLAYER2;

        hexInfos.push_back(new HexInfo(posX,posY,o));
    }

    return hexInfos;
}
void GameSaver::saveBoardstate(const std::vector<std::vector<Hex *>> &boardState, const Owner &playerTurn, const int &save)
{
    std::vector<HexInfo> hexInfos= {};

    //convert boardstate to hexinfos
    for (int i = 0; i < boardState.size(); i++)
    {
        for (int j = 0;j<boardState[i].size();j++)
        {
            hexInfos.push_back(HexInfo(boardState[i][j]->getPosX(),boardState[i][j]->getPosY(),boardState[i][j]->getOwner()));
        }
    }

    hexInfos.push_back(HexInfo(0,0,playerTurn));
    std::string fileName = "Saves/SaveFile" + std::to_string(save) + ".hex";
    saveHexInfoToFile(hexInfos,fileName);
}

void GameSaver::saveHexInfoToFile(std::vector<HexInfo> &infos,std::string file)
{
    auto openedFile = std::fstream(file, std::ios::out);
    for(HexInfo hi : infos)
    {
        openedFile << std::to_string(hi.posx) << " ";
        openedFile << std::to_string(hi.posy) << " ";
        int own = 0;
        switch (hi.owner)
        {
            case Owner::PLAYER1:
                own=1;
                break;
            case Owner::PLAYER2:
                own=2;
                break;
        }
        openedFile << std::to_string(own) << "\n";
    }
}


void GameSaver::trySaveNewHighscore(const int &newHighscore, const Owner &owner) {

}
/*
std::vector<HexInfo*> GameSaver::buildEmptyBoard()
{
    std::vector<HexInfo*> hexInfos={};
    for(int i = 0;i<5;i++)
    {
        for (int j = 0; j<i+5;j++)
        {
            if((i==4 && j==3) || (i == 3 && j == 4))
                continue;
            hexInfos.push_back(new HexInfo(i,j,Owner::NO_ONE));
            //boardState[i].push_back(new Hex(i,j,radius,window,Owner::NO_ONE));

        }
    }
    for (int i = 0; i<4;i++)
    {
        for(int j = 0; j<8-i;j++)
        {
            if(i==0 && j == 4)
                continue;
            hexInfos.push_back(new HexInfo(i,j,Owner::NO_ONE));
        }
    }

    return hexInfos;
}

int GameSaver::maxSavedGames() {
    return 3;
}*/

HexInfo::HexInfo(int i, int j, Owner owner): posx(i),posy(j),owner(owner){

}
