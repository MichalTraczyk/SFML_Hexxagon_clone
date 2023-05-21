//
// Created by Michał on 30.04.2023.
//

#include "Background.h"
#include "cmath"
#include <stdlib.h>
#include <iostream>
#include "Star.h"
Background::Background(sf::RenderWindow &window) : window(window)
{
    for(int i = 0; i<starsCount;i++)
    {
        Star s = Star();
        setupStar(s,true);
        stars.push_back(s);
    }
}

void Background::drawBackground(float deltaTime)
{
    moveStars(deltaTime);
    for(int i = 0; i<stars.size() ; i++)
    {
        sf::CircleShape *s = stars[i].getShape();

        if(s->getPosition().x < 0)
        {
            stars.erase(stars.begin()+i);
            Star newStar = Star();
            setupStar(newStar);
            stars.insert(stars.begin()+i,newStar);
        }
        window.draw(*s);
    }
}


void Background::moveStars(float deltaTime) {
    for (int i = 0; i < stars.size(); ++i) {
        stars[i].move(deltaTime);
    }
}

void Background::setupStar(Star &s, bool startSetup) {
        int radius = minSize + rand()%(maxSize-minSize);
        int x;
        int y = rand()%window.getSize().y;
        if(!startSetup)
            x = window.getSize().x;
        else
            x = rand()%window.getSize().x;


        int speed = minSpeed + rand()%(maxSpeed-minSpeed);
        s.reset(radius,speed,sf::Vector2<int>(x,y));
}
