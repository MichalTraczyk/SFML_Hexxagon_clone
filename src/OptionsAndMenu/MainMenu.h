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

private:

    MenuState currentMenuState = MenuState::MAIN_MENU;
    bool againstAI = false;
    sf::Font font;
    MainMenu* thisMenu;
    sf::RenderWindow &window;
    GameManager *gameManager;
    std::vector<Button*>* buttonsToShow;

    std::vector<Button*> mainMenuButtons = {};
    std::vector<Button*> loadGameButtons = {};
    std::vector<Button*> highscoreButtons = {};
    std::vector<Button*> gamemodeButtons = {};

    Button* backButton;

    sf::Vector2<float> buttonSize = sf::Vector2<float>(400.0f,50.0f);

    float buttonSpacing = 50;
    float buttonTopSpacing = 70;
    void NewGameButtonClicked();
    void LoadGameButtonClicked();
    void HighscoresButtonClicked();
    void GamemodeButtonClicked();

    void setupMainMenuButtons();

    void setupHighscores();

    void setupLoadGame();

    void setupGamemode();

    void setAIDecision(const bool &newDecision);
};


#endif //HEXXAGON_MAINMENU_H
