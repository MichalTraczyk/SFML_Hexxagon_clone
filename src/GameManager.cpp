//
// Created by Michał on 21.05.2023.
//

#include <iostream>
#include "GameManager.h"
#include "GameSaver.h"

GameManager::GameManager(sf::RenderWindow &w) : window(w)
{
    currentGameState=GameState::MENU;
    background =new  Background(window);
    mainMenu = new MainMenu(window,this);
    GameSaver::getBoardStateFromSave(0);
}
void GameManager::Update()
{
    deltaTime = clock.restart().asSeconds();
    background->drawBackground(deltaTime);

    switch (currentGameState) {
        case GameState::MENU:
            mainMenu->Update();
            break;
        case GameState::GAME:
            board->Update(deltaTime);
            break;
    }
}
void GameManager::startGame()
{
    bool ai = mainMenu->getAIDecision();
    board = new Board(window,ai,0);
    currentGameState=GameState::GAME;
}
void GameManager::onMouseButtonClicked(sf::Vector2<float> position)
{
    if(currentGameState == GameState::MENU)
    {
        mainMenu->onMouseButtonClicked(position);
    }
    else if( currentGameState == GameState::GAME)
    {
        board->OnMouseClicked(position);
    }
}
void GameManager::onEscapeButtonClicked()
{
    if(currentGameState == GameState::MENU)
    {
        mainMenu->Back();
    }
    else if( currentGameState == GameState::GAME)
    {
        board->OnEscapeClicked();
    }
}

