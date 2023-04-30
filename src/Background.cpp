//
// Created by Michał on 30.04.2023.
//

#include "Background.h"
#include "cmath"
Background::Background(sf::RenderWindow &window) {

}

void Background::drawBackground()
{
    sf::Time elapsedTime = clock.restart();
    for (int i = 0; i < stars.size(); ++i) {
        float speed = minSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxSpeed-minSpeed)));
        float move = elapsedTime.asSeconds() * speed;
        stars[i].move(sf::Vector2<float>(-move,0));
    }
}
