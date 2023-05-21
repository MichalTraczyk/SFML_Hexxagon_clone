//
// Created by Michał on 21.05.2023.
//

#include <iostream>
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &w) : window(w)
{
    currentGameState=GameState::MENU;
    background =new  Background(window);
    mainMenu = new MainMenu(window,this);
}
void GameManager::Update()
{
    deltaTime = clock.restart().asSeconds();

    sf::RectangleShape sh = sf::RectangleShape();
    sh.setSize(sf::Vector2f(100,100));
    sh.setPosition(0,0);
    window.draw(sh);

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
    board = new Board(window,ai);
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
