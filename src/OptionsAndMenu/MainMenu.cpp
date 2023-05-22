//
// Created by Michał on 21.05.2023.
//

#include "MainMenu.h"
#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &w, GameManager *gm) : window(w), gameManager(gm)
{
    setupMainMenuButtons();
    setupLoadGame();
    setupHighscores();
    setupGamemode();
    buttonsToShow = &mainMenuButtons;

    backButton =
            new Button("Back",[this]()
            {
                this->Back();
            },sf::Vector2<float>(window.getSize().x - buttonSize.x - buttonTopSpacing,window.getSize().y - buttonSize.y - buttonTopSpacing),buttonSize);
}


void MainMenu::Update()
{
    for(Button *b : *buttonsToShow)
    {
        b->draw(window);
    }
    if(currentMenuState!= MenuState::MAIN_MENU)
        backButton->draw(window);
}
void MainMenu::Back()
{
    buttonsToShow = &mainMenuButtons;
    currentMenuState = MenuState::MAIN_MENU;
}

//setting up different main menu submenus
void MainMenu::setupMainMenuButtons()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;

    mainMenuButtons.push_back(
            new Button("New game",[this]()
            {
                this->NewGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize));
    positionY += buttonSize.y + buttonSpacing;
    mainMenuButtons.push_back(
            new Button("Load game",[this]()
            {
                this->LoadGameButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    mainMenuButtons.push_back(
            new Button("Highscores",[this]()
            {
                this->HighscoresButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
    positionY += buttonSize.y + buttonSpacing;
    mainMenuButtons.push_back(
            new Button("Chose gamemode",[this]()
            {
                this->GamemodeButtonClicked();
            },sf::Vector2<float>(positionX,positionY),buttonSize)
    );
}
void MainMenu::setupLoadGame()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;
    for(int i = 0 ; i<3;i++)
    {
        std::string str = "Game " + std::to_string(i+1);

        loadGameButtons.push_back(
                new Button(str,[this]()
                {
                    ;
                },sf::Vector2<float>(positionX,positionY),buttonSize));
        positionY += buttonSize.y + buttonSpacing;
    }
}
void MainMenu::setupHighscores()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;
    for(int i = 0 ; i<3;i++)
    {
        std::string str = "Highscore: " + std::to_string(i+1);

        highscoreButtons.push_back(
                new Button(str,[this]()
                {
                    ;
                },sf::Vector2<float>(positionX,positionY),buttonSize));

        positionY += buttonSize.y + buttonSpacing;
    }
}
void MainMenu::setupGamemode()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;

    gamemodeButtons.push_back(
            new Button("PvP",[this]()
            {
                this->setAIDecision(false);
            },sf::Vector2<float>(positionX,positionY),buttonSize));

    positionY += buttonSize.y + buttonSpacing;

    gamemodeButtons.push_back(
            new Button("PvE",[this]()
            {
                this->setAIDecision(true);
            },sf::Vector2<float>(positionX,positionY),buttonSize));
}


//On click actions

void MainMenu::onMouseButtonClicked(sf::Vector2<float> position)
{
    if(backButton->contains(position))
    {
        backButton->click();
        return;
    }
    for(Button *b : *buttonsToShow)
    {
        if(b->contains(position))
        {
            b->click();
            return;
        }
    }
}

void MainMenu::NewGameButtonClicked()
{
    gameManager->startGame();
}
void MainMenu::LoadGameButtonClicked()
{
    buttonsToShow = &loadGameButtons;
    currentMenuState = MenuState::LOAD_GAME;
}
void MainMenu::HighscoresButtonClicked()
{
    buttonsToShow=&highscoreButtons;
    currentMenuState = MenuState::HIGHSCORES;
}
void MainMenu::GamemodeButtonClicked()
{
    buttonsToShow=&gamemodeButtons;
    currentMenuState = MenuState::GAMEMODE;
}


void MainMenu::setAIDecision(const bool &newDecision)
{
    againstAI = newDecision;
    this->Back();
}
bool MainMenu::getAIDecision() {
    return againstAI;
}
