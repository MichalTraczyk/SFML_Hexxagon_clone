#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "Board/Hex/Hex.h"
#include "iostream"
#include "Owner.h"
#include "Background/Background.h"
#include "AI.h"
#include "OptionsAndMenu/Button.h"
#include "GameManager.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    //Board b = Board(window,true);
    //Background background = Background(window);

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

        }
        window.clear();

        manager.Update();

        window.display();
    }

    return 0;
}