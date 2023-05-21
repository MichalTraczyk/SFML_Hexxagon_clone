//
// Created by Michał on 21.05.2023.
//

#include "MainMenu.h"
#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &w, GameManager *gm) : window(w), gameManager(gm)
{
    float positionX = w.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = 50;

    buttons.push_back(
            new Button("New game",[this]()
            {
                this->NewGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize));



    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Load game",[this]()
            {
                this->LoadGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Highscores",[this]()
            {
                this->HighscoresButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Chose gamemode",[this]()
            {
                this->GamemodeButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );




}
void MainMenu::Update()
{
    for(int i = 0; i<buttons.size();i++)
    {
        buttons[i]->draw(window);
    }
}
void MainMenu::NewGameButtonClicked()
{
    std::cout<<"game manager when starting game: " << gameManager<<std::endl;
    gameManager->startGame();
}
void MainMenu::LoadGameButtonClicked()
{
    std::cout<<"load game button clicked!"<<std::endl;
}
void MainMenu::HighscoresButtonClicked()
{
    std::cout<<"highscores button clicked!"<<std::endl;
}
void MainMenu::GamemodeButtonClicked()
{
    std::cout<<"gamemode button clicked!"<<std::endl;
}

bool MainMenu::getAIDecision() {
    return true;
}

void MainMenu::onMouseButtonClicked(sf::Vector2<float> position)
{
    std::cout<<"mouse clicked!"<<std::endl;
    for(Button *b : buttons)
    {
        if(b->contains(position))
            b->click();
    }
}
