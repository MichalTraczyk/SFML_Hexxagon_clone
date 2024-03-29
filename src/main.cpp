#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "GameManager.h"
#include "GameSaver.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    GameManager manager = GameManager(window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed)
            {
                manager.onMouseButtonClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
            if(event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                manager.onEscapeButtonClicked();
            }
        }
        window.clear();

        manager.Update();

        window.display();
    }

    return 0;
}