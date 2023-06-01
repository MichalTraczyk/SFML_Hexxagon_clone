//
// Created by Michał on 01.05.2023.
//

#ifndef HEXXAGON_BUTTON_H
#define HEXXAGON_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

/**
* @brief Class that represents button in Main menu
 *
 * It handles drawing of button gfx and stores on click event
*/
class Button
{
public:

    Button(const std::string &text, std::function<void()> onClick, const sf::Vector2<float> &position,
           const sf::Vector2<float> &size);

    /**
    * @brief Invokes action specified in constructor
    */
    void click();
    /**
    * @brief checks if position is inside of the button
     * @param pos position to check
     * @return boolean if pos is inside
    */
    bool contains(const sf::Vector2<float> &pos);

    /**
    * @brief Draws button gfx
     *
     * @param window Target window
    */
    void draw(sf::RenderWindow &window);

private:
    std::function<void ()> onClick;

    //button visuals
    sf::Color buttonColor = sf::Color::Cyan;
    sf::RectangleShape shape;
    sf::Text buttonText;

    sf::Font font;

};


#endif //HEXXAGON_BUTTON_H
