//
// Created by Michał on 01.05.2023.
//

#include <iostream>
#include "Button.h"


Button::Button(const std::string &text, void* onClick,const sf::Vector2<float> &position,const sf::Vector2<float> &size) : onClick(onClick)
{
    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    shape = sf::RectangleShape();
    shape.setSize(size);
    shape.setPosition(position);
}

void Button::click()
{
    if(onClick != nullptr)
    {
        onClick();
    }
}
bool Button::contains(const sf::Vector2<float> pos) {
    return shape.getLocalBounds().contains(pos);
}

Button::Button(void* onClick, const sf::Vector2<float> &position, const sf::Vector2<float> &size) : onClick(onClick)
{
    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    shape = sf::RectangleShape();
    shape.setSize(size);
    shape.setPosition(position);
}

Button::Button(std::function<void()> fn) {

}

