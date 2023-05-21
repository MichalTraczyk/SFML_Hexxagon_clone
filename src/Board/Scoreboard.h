//
// Created by Michał on 20.05.2023.
//

#ifndef HEXXAGON_SCOREBOARD_H
#define HEXXAGON_SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include "Hex/Hex.h"

class Scoreboard {
public:
    Scoreboard(sf::RenderWindow &w, std::vector<std::vector<Hex*>> &bs);

    void drawScoreboard();

    void calculateScoreboard();

private:
    sf::Font font;
    sf::RenderWindow &window;

    int player1Score = 0;
    int player2Score = 0;

    const int scoreBoardDownDistance = 100;
    const int scoreBoardRightDistance = 500;

    const int scoreboardRectHeight = 35;
    const int scoreboardRectWidthMultiplier = 10;

    sf::RectangleShape player1PointsRect;
    sf::RectangleShape player2PointsRect;

    sf::Text player1PointsText;
    sf::Text player2PointsText;

    void buildScoreboard();

    void recalculatePoints();

    std::vector<std::vector<Hex*>> &boardState;
};


#endif //HEXXAGON_SCOREBOARD_H
