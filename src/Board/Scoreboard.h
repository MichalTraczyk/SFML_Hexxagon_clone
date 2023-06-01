//
// Created by Michał on 20.05.2023.
//

#ifndef HEXXAGON_SCOREBOARD_H
#define HEXXAGON_SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include "Hex/Hex.h"
/**
 * @brief class that handles game logic
*/
class Scoreboard {
public:
    Scoreboard(sf::RenderWindow &w, std::vector<std::vector<Hex*>> &bs);

    /**
    * @brief Draws scoreboard
     * Draws bars of player points and points values
    */
    void drawScoreboard();

    /**
    * @brief Calculates score bar length for each player
    */
    void calculateScoreboard();
    /**
    * @brief returns score of each player as vector2
     * x - Player 1 score
     * y - Player 2 score
     * @return vector2 of scores
    */
    sf::Vector2<int> getScore();

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

    /**
    * @brief Generates bar shape and text for visual represenation of each player points
    */
    void buildScoreboard();

    /**
    * @brief Calculates each player score
    */
    void recalculatePoints();

    std::vector<std::vector<Hex*>> &boardState;
};


#endif //HEXXAGON_SCOREBOARD_H
