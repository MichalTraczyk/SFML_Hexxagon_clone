//
// Created by Michał on 20.05.2023.
//

#include "MainMenu.h"

void fun()
{
    ;
}
MainMenu::MainMenu(sf::RenderWindow &w) : window(w)
{
    void *fun = Play;

    Button b = Button(fun);
    //Button playButton = Button("Play",Play(),sf::Vector2<float>(1.0f,1.0f),buttonSize);
    //Button playButton = Button(Play,sf::Vector2<float>(1.0f,1.0f),buttonSize);
    //Button playButton = Button(Play);
    //Button playButton = Button(str,Play(),sf::Vector2<float>(1.0f,1.0f),buttonSize);
    //buttons.push_back(Button());
}

void MainMenu::Play() {

}

void MainMenu::Options() {

}

void MainMenu::Exit() {

}
