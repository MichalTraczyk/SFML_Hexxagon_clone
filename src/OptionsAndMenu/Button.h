//
// Created by Michał on 01.05.2023.
//

#ifndef HEXXAGON_BUTTON_H
#define HEXXAGON_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:

    Button(const std::string &text, std::function<void()> onClick, const sf::Vector2<float> &position,
           const sf::Vector2<float> &size);

    void click();
    bool contains(sf::Vector2<float> pos);

//on click
void draw(sf::RenderWindow &window);

private:
    //Button visuals
    std::function<void ()> onClick;

    sf::Color buttonColor = sf::Color::Cyan;
    sf::RectangleShape shape;
    sf::Text buttonText;

    sf::Font font;

};


#endif //HEXXAGON_BUTTON_H
