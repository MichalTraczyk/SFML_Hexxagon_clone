#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "Board/Hex/Hex.h"
#include "iostream"
#include "Owner.h"
#include "Background/Background.h"
#include "AI.h"
#include "OptionsAndMenu/Button.h"

void MyFunction()
{
    std::cout<<"UWU OWO";
}
int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    Board b = Board(window,true);
    Background background = Background(window);

    Button bt = Button(MyFunction);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed)
                b.OnMouseClicked(sf::Vector2<int>(event.mouseButton.x, event.mouseButton.y));

        }
        window.clear();
        background.drawBackground();
        b.Update();
        window.display();
    }

    return 0;
}