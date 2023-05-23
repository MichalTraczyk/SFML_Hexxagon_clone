//
// Created by Michał on 21.05.2023.
//

#include "MainMenu.h"
#include <iostream>
#include "MainMenu.h"
#include "../GameSaver.h"

MainMenu::MainMenu(sf::RenderWindow &w, GameManager *gm) : window(w), gameManager(gm)
{
    setupMainMenuButtons();
    setupLoadGame();
    setupHighscores();
    setupGamemode();

    currentMenuState = MenuState::MAIN_MENU;

    backButton =
            new Button("Back",[this]()
            {
                this->Back();
            },sf::Vector2<float>(window.getSize().x - buttonSize.x - buttonTopSpacing,window.getSize().y - buttonSize.y - buttonTopSpacing),buttonSize);
}


void MainMenu::Update()
{
    for(Button *b : *buttonsOfMenuStates[currentMenuState])
    {
        b->draw(window);
    }
    if(currentMenuState!= MenuState::MAIN_MENU)
        backButton->draw(window);
}
void MainMenu::Back()
{
    currentMenuState = MenuState::MAIN_MENU;
}

void MainMenu::enableSaveUI(std::vector<std::vector<Hex*>>* s,Owner t)
{
    currentMenuState=MenuState::SAVE_GAME;
    boardstateToSave = s;
    turnToSave=t;


    for(auto p : saveGameButtons)
    {
        delete p;
    }
    saveGameButtons.clear();

    setupSaveGame();
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



    buttonsOfMenuStates[MenuState::MAIN_MENU] = &mainMenuButtons;
}
void MainMenu::setupLoadGame()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;
    for(int i = 0 ; i<GameSaver::maxSavedGames();i++)
    {
        int save = -1;
        std::string str="";

        if(GameSaver::doesSavesExist(i))
        {
            str = "save " + std::to_string(i+1);
            save = i;
        }
        else
        {
            str = "empty";
        }

        loadGameButtons.push_back(
                new Button(str,[this,save]()
                {
                    selectSave(save);
                },sf::Vector2<float>(positionX,positionY),buttonSize));
        positionY += buttonSize.y + buttonSpacing;
    }

    buttonsOfMenuStates[MenuState::LOAD_GAME] = &loadGameButtons;
}
void MainMenu::setupSaveGame()
{
    float positionX = window.getSize().x/2;
    positionX-= buttonSize.x/2;

    float positionY = buttonTopSpacing;
    for(int i = 0 ; i<GameSaver::maxSavedGames();i++)
    {
        std::string str="";
        int save = i;
        if(GameSaver::doesSavesExist(i))
        {
            str = "override " + std::to_string(i+1);
        }
        else
        {
            str = "empty";
        }

        saveGameButtons.push_back(
                new Button(str,[this,save]()
                {
                    saveGame(save);
                },sf::Vector2<float>(positionX,positionY),buttonSize));
        positionY += buttonSize.y + buttonSpacing;
    }

    buttonsOfMenuStates[MenuState::SAVE_GAME] = &saveGameButtons;
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

    buttonsOfMenuStates[MenuState::HIGHSCORES] = &highscoreButtons;
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


    buttonsOfMenuStates[MenuState::GAMEMODE] = &gamemodeButtons;
}


//On click actions
void MainMenu::onMouseButtonClicked(sf::Vector2<float> position)
{
    if(backButton->contains(position))
    {
        backButton->click();
        return;
    }
    for(Button *b : *buttonsOfMenuStates[currentMenuState])
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
    gameManager->startGame(-1);
}
void MainMenu::LoadGameButtonClicked()
{
    currentMenuState = MenuState::LOAD_GAME;
}
void MainMenu::HighscoresButtonClicked()
{
    currentMenuState = MenuState::HIGHSCORES;
}
void MainMenu::GamemodeButtonClicked()
{
    currentMenuState = MenuState::GAMEMODE;
}


void MainMenu::selectSave(int save)
{
    if(save!=-1)
        gameManager->startGame(save);
}
void MainMenu::saveGame(int where)
{
    if(boardstateToSave!= nullptr)
    {
        GameSaver::saveBoardstate(*boardstateToSave,turnToSave,where);

        for(auto p : loadGameButtons)
        {
            delete p;
        }
        loadGameButtons.clear();
        setupLoadGame();

        gameManager->onGameSaved();

        currentMenuState=MenuState::MAIN_MENU;

    }
}


void MainMenu::setAIDecision(const bool &newDecision)
{
    againstAI = newDecision;
    this->Back();
}
bool MainMenu::getAIDecision() {
    return againstAI;
}