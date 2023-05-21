//
// Created by Michał on 21.05.2023.
//

#ifndef HEXXAGON_GAMEMANAGER_H
#define HEXXAGON_GAMEMANAGER_H


#include "Board/Board.h"
#include "OptionsAndMenu/MainMenu.h"
#include "Background/Background.h"
#include "GameState.h"

class GameManager {
public:
    GameManager(sf::RenderWindow &window);
    void Update();

    void onMouseButtonClicked(sf::Vector2<int> position);

private:
    sf::Clock clock;
    float deltaTime;
    sf::RenderWindow &window;

    GameState currentGameState = GameState::MENU;
    Background* background;
    Board* board;
    MainMenu* mainMenu;

    void StartGame();

};


#endif //HEXXAGON_GAMEMANAGER_H
