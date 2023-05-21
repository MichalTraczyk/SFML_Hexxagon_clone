//

#include <iostream>
#include "Scoreboard.h"

//
// Created by Michał on 20.05.2023.
Scoreboard::Scoreboard(sf::RenderWindow &w, std::vector<std::vector<Hex*>> &bs) : window(w), boardState(bs){
    buildScoreboard();
    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
}
void Scoreboard::buildScoreboard()
{
    //creating rects
    player1PointsRect = sf::RectangleShape(sf::Vector2f(0,scoreboardRectHeight));
    player2PointsRect = sf::RectangleShape(sf::Vector2f(0,scoreboardRectHeight));

    //colors
    player1PointsRect.setFillColor(sf::Color::Green);
    player2PointsRect.setFillColor(sf::Color::Cyan);

    //setting up positions
    player1PointsRect.setPosition(window.getSize().x - scoreBoardRightDistance,window.getSize().y - scoreBoardDownDistance);
    player2PointsRect.setPosition(window.getSize().x - scoreBoardRightDistance,(window.getSize().y - scoreBoardDownDistance) - scoreboardRectHeight*2);


    //setting up text
    player1PointsText.setFont(font); // font is a sf::Font
    player1PointsText.setPosition(player1PointsRect.getPosition().x,player1PointsRect.getPosition().y);
    player1PointsText.setCharacterSize(scoreboardRectHeight-3);
    player1PointsText.setFillColor(sf::Color::White);

    player2PointsText.setFont(font); // font is a sf::Font
    player2PointsText.setPosition(player2PointsRect.getPosition().x,player2PointsRect.getPosition().y);
    player2PointsText.setCharacterSize(scoreboardRectHeight-3);
    player2PointsText.setFillColor(sf::Color::White);
}
void Scoreboard::calculateScoreboard()
{
    recalculatePoints();
    player1PointsRect.setSize(sf::Vector2f(player1Score*scoreboardRectWidthMultiplier,player1PointsRect.getSize().y));
    player2PointsRect.setSize(sf::Vector2f(player2Score*scoreboardRectWidthMultiplier,player2PointsRect.getSize().y));

    player1PointsText.setString(std::to_string(player1Score));
    player2PointsText.setString(std::to_string(player2Score));
}

void Scoreboard::drawScoreboard()
{
    window.draw(player1PointsRect);
    window.draw(player2PointsRect);

    window.draw(player1PointsText);
    window.draw(player2PointsText);
}

void Scoreboard::recalculatePoints()
{
    player1Score=0;
    player2Score=0;
    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            if(boardState[i][j]->getOwner() == Owner::PLAYER1)
                player1Score++;

            if(boardState[i][j]->getOwner() == Owner::PLAYER2)
                player2Score++;
        }
    }
}