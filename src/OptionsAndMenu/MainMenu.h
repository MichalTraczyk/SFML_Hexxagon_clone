//
// Created by Michał on 21.05.2023.
//

#ifndef HEXXAGON_MAINMENU_H
#define HEXXAGON_MAINMENU_H

class GameManager;
#include "../GameManager.h"
#include "Button.h"

class MainMenu {

public:
    MainMenu(sf::RenderWindow &w, GameManager* gameManager);

    bool getAIDecision();

    void Update();

    void onMouseButtonClicked(sf::Vector2<float> position);

private:

    MainMenu* thisMenu;
    sf::RenderWindow &window;
    GameManager *gameManager;
    std::vector<Button*> buttons = {};
    sf::Vector2<float> buttonSize = sf::Vector2<float>(300.0f,50.0f);
    float buttonSpacing = 50;
    void NewGameButtonClicked();
    void LoadGameButtonClicked();
    void HighscoresButtonClicked();
    void GamemodeButtonClicked();

};


#endif //HEXXAGON_MAINMENU_H
