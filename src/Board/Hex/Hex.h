//
// Created by Michaś on 28.04.2023.
//

#ifndef HEXXAGON_HEX_H
#define HEXXAGON_HEX_H

#include <SFML/Graphics.hpp>
#include "../../Owner.h"
#include "HexState.h"

/**
* @brief class that manages hex gfx and current state
*/
class Hex
{
public:

    ~Hex();
    Hex(int posX,int posY, const int &radius,sf::RenderWindow &window,Owner owner = Owner::PLAYER1);

    /**
    * @brief return X position of the Hex in board coordinates
     * @return X coordinate in board coordinates
    */
    int getPosX();
    /**
    * @brief return Y position of the Hex in board coordinates
     * @return Y coordinate in board coordinates
    */
    int getPosY();

    /**
    * @brief Moves hex in window
    */
    void Move(sf::Vector2<int> move);

    /**
    * @brief returns window position of the Hex in window coordinates
     * @return coordinates in window coordinates
    */
    sf::Vector2<int> getWindowPosition();

    /**
    * @brief return Owner of the hex
    * @return Owner of the hex
    */
    Owner getOwner();
    /**
    * @brief sets owner of this hex
    */
    void setOwner(Owner owner);

    /**
    * @brief changes state of hex to selected
    */
    void select();
    /**
    * @brief changes state of hex to unselected
    */
    void unselect();

    /**
    * @brief detects if position is inside hex
     *
     * @param pos Positon to check
     * @return bool if position is inside hex
     *
    */
    bool contains(sf::Vector2<float> pos);
    /**
    * @brief draws hex in the window
    */
    void drawHex();
    /**
    * @brief draws outlien of hex in the window
     * outline depends on current hex state
    */
    void drawOutline();

    /**
    * @brief returns current state of hex
     * @return hex state
    */
    HexState getState();

    /**
    * @brief sets hex state
    */
    HexState setState(HexState newState);

private:

    int positionX;
    int positionY;
    int windowXPosition;
    int windowYPosition;
    int radius;

    /**
    * @brief calculates verticies of hexagonal shape
    */
    void generateShape();

    sf::ConvexShape shape;
    sf::ConvexShape outline;
    sf::ConvexShape selectObject;

    /**
    * @brief calculates window position of this hex
    */
    void calculateCoordinates(const int &radius);
    sf::RenderWindow &window;
    Owner owner;
    HexState state;

};


#endif //HEXXAGON_HEX_H
