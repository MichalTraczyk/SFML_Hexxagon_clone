//
// Created by Michał on 21.05.2023.
//

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &w) : window(w)
{
    background =new  Background(window);
    mainMenu = new MainMenu(w);
    mainMenu->setGameManager(this);
}
void GameManager::Update()
{
    deltaTime = clock.restart().asSeconds();

    background->drawBackground(deltaTime);


    if(currentGameState == GameState::MENU)
    {
        mainMenu->Update();
    }
    else if( currentGameState == GameState::GAME)
    {
        board->Update(deltaTime);
    }
}
void GameManager::StartGame()
{
    board = new Board(window,mainMenu->getAIDecision());
    currentGameState=GameState::GAME;
}
void GameManager::onMouseButtonClicked(sf::Vector2<int> position)
{
;
}
