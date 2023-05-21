//
// Created by Michał on 01.05.2023.
//

#include <iostream>
#include "Button.h"


Button::Button(const std::string &text, std::function<void()> onClick,const sf::Vector2<float> &position,const sf::Vector2<float> &size) : onClick(onClick)
{
    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    shape = sf::RectangleShape();
    shape.setSize(size);
    shape.setPosition(position);

    //set text
    // select the font
    buttonText.setFont(font); // font is a sf::Font

    // set the string to display
    //std::string t = std::to_string(h.getPosX()) + " " + std::to_string(h.getPosY());
    buttonText.setString(text);

    buttonText.setPosition(position.x, position.y);
    // set the character size
    buttonText.setCharacterSize(size.y - 2) ; // in pixels, not points!

    // set the color
    buttonText.setFillColor(sf::Color::Black);

    // set the text style
    buttonText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // inside the main loop, between window.clear() and window.display()
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
void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(buttonText);
}

