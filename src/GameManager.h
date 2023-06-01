//
// Created by Michał on 21.05.2023.
//

#ifndef HEXXAGON_GAMEMANAGER_H
#define HEXXAGON_GAMEMANAGER_H


class Board;
#include "Board/Board.h"
class MainMenu;
#include "OptionsAndMenu/MainMenu.h"
#include "Background/Background.h"
#include "GameState.h"

/**
* @brief Class that manages current game state
 * Manages if the game should be in main menu, game view etc
*/
class GameManager {
public:
    /**
    * @brief Class constructor
     * @param window Main window
    */
    GameManager(sf::RenderWindow &window);

    /**
    * @brief Called every frame
     *Calls updates from other scripts
    */
    void Update();

    /**
    * @brief Event called when mouse button is clicked
     *Calls same event from other scripts
     * @param position screen position of mouse
    */
    void onMouseButtonClicked(sf::Vector2<float> position);

    /**
    * @brief Starts the game
     * Creates the board object and changes the game state
     * @param save save to load, -1 means new save
    */
    void startGame(int save);

    /**
 * @{ @name Event listeners
 */
    /**
     * @brief Event listeners
     *
     */
    void onEscapeButtonClicked();
    void onGameSaved();
    void onGameFinished();
    /**
     * @}
     */


private:
    sf::RenderWindow &window;


    sf::Clock clock;
    float deltaTime;
    GameState currentGameState = GameState::MENU;


    MainMenu* mainMenu;
    Background* background;
    Board* board;

};


#endif //HEXXAGON_GAMEMANAGER_H
