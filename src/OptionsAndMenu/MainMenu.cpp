//
// Created by Michał on 20.05.2023.
//

#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &w) : window(w)
{
    MainMenu mm = *this;

    Button playButton = Button("Play",[&mm]()
      {
        mm.Play();
      },sf::Vector2<float>(1.0f,1.0f),buttonSize);
}

void MainMenu::Play() {

}

void MainMenu::Options() {

}

void MainMenu::Exit() {

}
