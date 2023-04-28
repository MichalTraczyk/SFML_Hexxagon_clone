#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "Board/Hex.h"
#include "iostream"
#include "Owner.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    Board b = Board(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();
            b.drawBoard();
            window.display();
        }
    }

    return 0;
}