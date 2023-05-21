//
// Created by Michał on 21.05.2023.
//

#include "MainMenu.h"
#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &w) : window(w)
{
    MainMenu mm = *this;
    float positionX = w.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = 50;

    buttons.push_back(
            new Button("New game",[&mm]()
            {
                mm.NewGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize));

    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Load game",[&mm]()
            {
                mm.LoadGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Highscores",[&mm]()
            {
                mm.HighscoresButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    buttons.push_back(
            new Button("Chose gamemode",[&mm]()
            {
                mm.GamemodeButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)

    );

}
void MainMenu::setGameManager(GameManager* gm)
{
    gameManager = gm;
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
    std::cout<<"Play button clicked!"<<std::endl;
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