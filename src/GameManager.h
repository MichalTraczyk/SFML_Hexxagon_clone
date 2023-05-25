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


class GameManager {
public:
    GameManager(sf::RenderWindow &window);
    void Update();
    void onMouseButtonClicked(sf::Vector2<float> position);
    void startGame(int save);
    void onEscapeButtonClicked();
    void onGameSaved();

    void onGameFinished();

private:
    sf::Clock clock;
    float deltaTime;
    sf::RenderWindow &window;
    GameState currentGameState = GameState::MENU;
    MainMenu* mainMenu;
    Background* background;
    Board* board;

};


#endif //HEXXAGON_GAMEMANAGER_H
