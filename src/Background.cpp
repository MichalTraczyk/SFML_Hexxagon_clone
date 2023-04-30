//
// Created by Michał on 30.04.2023.
//

#include "Background.h"
#include "cmath"
#include <stdlib.h>
Background::Background(sf::RenderWindow &window)
{
    for(int i = 0; i<starsCount;i++)
    {
        sf::CircleShape circle = sf::CircleShape();
        int radius = minSize + rand()%(maxSize-minSize);
        circle.setRadius(radius);

        int x = rand()%window.getSize().x;
        int y = rand()%window.getSize().y;

        circle.setPosition(x,y);
        stars.push_back(&circle);
    }
}

void Background::drawBackground()
{
    sf::Time elapsedTime = clock.restart();
    for (int i = 0; i < stars.size(); ++i) {
        int speed = minSpeed + (rand()% (maxSpeed-minSpeed));
        float move = elapsedTime.asSeconds() * speed;
        stars[i]->move(sf::Vector2<float>(-move,0));
        stars[i]->draw();
    }
}
