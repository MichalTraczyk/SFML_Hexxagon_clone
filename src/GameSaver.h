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

    /**
    * @brief Checks if save exists
     * @param saveNumber save to check
    */
    static bool doesSavesExist(int saveNumber);

    //saving and loading saves
    /**
    * @brief returns info about every hex on board basing on save
     * @param save save to check
     * @return vector of HexInfos
    */
    static std::vector<HexInfo*> getBoardStateFromSave(int save);

    /**
    * @brief Saves gameboard to file
     * @param boardState board to save
     * @param playerTurn player that starts the game
     * @param save save number
    */
    static void saveBoardstate(const std::vector<std::vector<Hex*>> &boardState, const Owner &playerTurn,const int &save);

    /**
    * @brief Tries to save new highscore to a file
     *
     * checks if score is higher than saved highscores and if it is, it saves it to file
     *
     * @param newHighscore score
     * @param owner score owner
    */
    static void trySaveNewHighscore(const int &newHighscore,const Owner &owner);



    /**
    * @brief Returns vector of highscores
     * @param owner owner of highscores
     * @return sorted vector of highscores
    */
    static std::vector<int> getHighscores(const Owner &owner);

private:

    /**
    * @brief Saves vector of HexInfos to file
     * @param infos vector of HexInfos to save
     * @param file target file directory
    */
    static void saveHexInfoToFile(std::vector<HexInfo> &infos,std::string file);

    /**
    * @brief Saves vector of highscores to file
     * @param v sorted vector of highscores
     * @param owner owner of highscores, '1' - player 1, '2' - player2
    */
    static void saveHighscoreToFile(std::vector<int> &v, char owner);
};


#endif //HEXXAGON_GAMESAVER_H
