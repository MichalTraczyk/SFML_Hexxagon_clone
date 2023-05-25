//
// Created by Michał on 21.05.2023.
//

#ifndef HEXXAGON_MAINMENU_H
#define HEXXAGON_MAINMENU_H

class GameManager;
#include "../GameManager.h"
#include "Button.h"
#include "MenuState.h"


class MainMenu {

public:
    MainMenu(sf::RenderWindow &w, GameManager* gameManager);

    bool getAIDecision();

    void Update();

    void onMouseButtonClicked(sf::Vector2<float> position);

    void Back();

    void enableSaveUI(std::vector<std::vector<Hex *>> *s, Owner t);
    void enableGameFinishedUI(sf::Vector2<int> stats);
private:
    sf::RenderWindow &window;
    GameManager *gameManager;

    //Game saving
    std::vector<std::vector<Hex*>>* boardstateToSave = nullptr;
    Owner turnToSave;
    void selectSave(int save);
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
    void NewGameButtonClicked();
    void LoadGameButtonClicked();
    void HighscoresButtonClicked();



    void GamemodeButtonClicked();
    void setupMainMenuButtons();
    void setupHighscores();
    void setupLoadGame();
    void setupGamemode();

    void setupSaveGame();


    //AI decision
    bool againstAI = false;
    void setAIDecision(const bool &newDecision);

    void setupEndgame(sf::Vector2<int> vector2);

};


#endif //HEXXAGON_MAINMENU_H
