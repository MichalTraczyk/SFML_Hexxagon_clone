//
// Created by Michał on 01.05.2023.
//

#include <iostream>
#include "Button.h"
using namespace std;

Button::Button(const std::string &text, std::function<void()> onClick,const sf::Vector2<float> &position,const sf::Vector2<float> &size) : onClick(onClick)
{
    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    shape = sf::RectangleShape();
    shape.setSize(size);
    shape.setPosition(position);

    buttonText.setFont(font);
    buttonText.setString(text);

    buttonText.setPosition(position.x, position.y);
    buttonText.setCharacterSize(size.y - 2) ;

    buttonText.setFillColor(sf::Color::Black);

    buttonText.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Button::click()
{
    if(onClick != nullptr)
    {
        onClick();
    }
}
bool Button::contains(const sf::Vector2<float> &pos)
{
    return shape.getGlobalBounds().contains(pos);
}
void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(buttonText);
}

