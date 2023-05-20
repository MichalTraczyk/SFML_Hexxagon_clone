//
// Created by Michał on 20.05.2023.
//

#ifndef HEXXAGON_MAINMENU_H
#define HEXXAGON_MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class MainMenu
{
public:
    MainMenu(sf::RenderWindow &window);
    void Play();
    void Options();
    void Exit();
private:
    sf::Vector2<float> buttonSize = sf::Vector2<float>(100.0f,50.0f);
    std::vector<Button> buttons = {};
    sf::RenderWindow &window;
};


#endif //HEXXAGON_MAINMENU_H
