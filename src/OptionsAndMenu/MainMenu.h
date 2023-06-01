//
// Created by Michał on 21.05.2023.
//

#ifndef HEXXAGON_MAINMENU_H
#define HEXXAGON_MAINMENU_H

class GameManager;
#include "../GameManager.h"
#include "Button.h"
#include "MenuState.h"

/**
* @brief Main menu class
 * Handles main menu navigation and basic logic
*/
class MainMenu {

public:
    /**
    * @brief Constructor of Main menu class
     * @param w Target window
     * @param gameManager game manager that handles main menu
    */
    MainMenu(sf::RenderWindow &w, GameManager* gameManager);


    /**
    * @brief Returns decision if player want to play against ai
     * @return Player decision
    */
    bool getAIDecision();

    /**
    * @brief Called every frame
     * Drawing is here
    */
    void Update();

    /**
    * @brief Called when player clicks left mouse button
     * Checks which button was clicked
    */
    void onMouseButtonClicked(sf::Vector2<float> position);

    /**
    * @brief Takes player to main menu
    */
    void Back();

    /**
    * @brief Enables UI when player wants to save something
     * @param boardstateToSave boardstate to save
     * @param nextPlayerTurn players turn to start saved game
    */
    void enableSaveUI(std::vector<std::vector<Hex *>> *boardstateToSave, Owner nextPlayerTurn);

    /**
    * @brief Enables UI when player finished the game
     *
     * @param stats game stats basing on which UI will be set
    */
    void enableGameFinishedUI(sf::Vector2<int> stats);
private:
    sf::RenderWindow &window;
    GameManager *gameManager;

    //Game saving
    std::vector<std::vector<Hex*>>* boardstateToSave = nullptr;
    Owner turnToSave;

    /**
    * @brief Lets playerto chose which save they want to play
     *Is called from button that contains the save number
     * @param save Desired save index
    */
    void selectSave(int save);

    /**
    * @brief Saves the game
     *Is called from button that contains the save number
     *
     * @param where Desired save index
    */
    void saveGame(int where);

    //Main menu navigation
    MenuState currentMenuState = MenuState::MAIN_MENU;
    std::map<MenuState, std::vector<Button*>*> buttonsOfMenuStates;

    std::vector<Button*> mainMenuButtons = {};
    std::vector<Button*> loadGameButtons = {};
    std::vector<Button*> saveGameButtons = {};
    std::vector<Button*> highscoreButtons = {};
    std::vector<Button*> gamemodeButtons = {};
    std::vector<Button*> endgameButtons = {};
    Button* backButton;


    //button vfx
    const sf::Vector2<float> buttonSize = sf::Vector2<float>(400.0f,50.0f);
    float buttonSpacing = 50;
    sf::Font font;


    float buttonTopSpacing = 70;

    /**
     * @{ @name Button listeners.
     */
    /**
     * @brief Button listeners.
     *
     * Methods that are invoked when buttons are clicked
     */
    void NewGameButtonClicked();
    void LoadGameButtonClicked();
    void HighscoresButtonClicked();
    void GamemodeButtonClicked();
    /**
     * @}
     */


    /**
     * @{ @name GFX setups.
     */
    /**
     * @brief Methods that setup Main Menu layout.
     *
     */
    void setupMainMenuButtons();
    void setupHighscores();
    void setupLoadGame();
    void setupGamemode();
    void setupSaveGame();
    void setupEndgame(sf::Vector2<int> vector2);
    /**
     * @}
     */

    //AI decision
    bool againstAI = false;
    /**
    * @brief Setter of player AI decision
     * @param newDecision new decision if player wants to play gainst AI
    */
    void setAIDecision(const bool &newDecision);

};


#endif //HEXXAGON_MAINMENU_H
