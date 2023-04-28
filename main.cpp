#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "Board/Hex.h"
#include "iostream"
#include "Owner.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    Board b = Board(window);

    Hex h = Hex(1,1);
    Hex h1 = Hex(2,1);
    Hex h2= Hex(1,2,Owner::NO_ONE);
    Hex h3 = Hex(2,2,Owner::NO_ONE);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();
            b.drawHex(h);
            b.drawHex(h1);
            b.drawHex(h2);
            b.drawHex(h3);

            window.display();
        }
    }

    return 0;
}