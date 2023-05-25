//
// Created by Michaś on 28.04.2023.
//

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "cmath"
#include "Hex/Hex.h"
#include "vector"
#include "../AI.h"
#include "../GameSaver.h"
#include <thread>

Board::Board(sf::RenderWindow &w, bool againstAI,GameManager* gm,const int &save) : window(w), againstAI(againstAI),gameManager(gm)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    if (!font.loadFromFile("Anton.ttf"))
    {
        std::cout<<"ERROR LOADING THE FONT";
    }
    //Creates vector of hexes
    buildBoard(save);

    //Offsets hexes so the board is in the middle
    offsetHexes();

    //Draws every hex according to its state and position
    drawBoard();
    //Scoreboard sc = Scoreboard(w,boardState);
    //scoreboard = sc;
    scoreboard = new Scoreboard(w,boardState);

}
void Board::Update(float deltaTime)
{
    if(againstAI && currentPlayerTurn == Owner::PLAYER2)
    {
        aiMoveTimer += deltaTime;
        if(aiMoveTimer>1)
        {
            AIMove();
            aiMoveTimer = 0;
        }
    }

    drawBoard();
    scoreboard->drawScoreboard();
}
void Board::drawBoard() {

    for(int i = 0; i<boardState.size(); i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            drawHex(*boardState[i][j]);
        }
    }
}
void Board::OnMouseClicked(sf::Vector2<float> position)
{
    if(againstAI && currentPlayerTurn==Owner::PLAYER2)
        return;

    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState.at(i).size();j++)
        {
            if(boardState.at(i).at(j)->contains(position))
            {
                if( boardState.at(i)[j]->getOwner() == currentPlayerTurn)
                    selectHex(*boardState.at(i).at(j));

                else if(boardState.at(i).at(j)->getState() == HexState::CLOSE)
                {
                    Move m = Move(*selectedHex, *boardState[i][j], false);
                    move(m);
                }
                else if(boardState.at(i).at(j)->getState() == HexState::VERY_CLOSE)
                {
                    Move m = Move(*selectedHex, *boardState[i][j], true);
                    move(m);
                }
            }
        }
    }
}
void Board::move(Move &m)
{
    m.where.setOwner(m.from.getOwner());

    if(!m.duplicate)
    {
        m.from.setOwner(Owner::NO_ONE);
    }

    //unselect everything
    unselectAllHexes();

    for(auto i : findCloseHexes(m.where))
    {
        if(i.first->getOwner() != Owner::NO_ONE && i.first->getOwner() != m.where.getOwner() && i.second <= 2)
        {
            i.first->setOwner(m.where.getOwner());
        }
    }

    scoreboard->calculateScoreboard();


    if(currentPlayerTurn==Owner::PLAYER1)
    {
        currentPlayerTurn = Owner::PLAYER2;
    }
    else {
        currentPlayerTurn = Owner::PLAYER1;
    }

    if(!CanMove(currentPlayerTurn))
    {
        onNoMoreMoves();
        return;
    }

}

bool Board::CanMove(Owner player)
{
    int max = 0;
    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            if(boardState[i][j]->getOwner() == player)
            {
                auto mapa = findPossibleMoves(*boardState[i][j]);
                if(mapa.size()>max)
                    max=mapa.size();
            }
        }
    }
    std::cout<<"Max of: " <<max <<std::endl;
    return max>0;

}
void Board::AIMove()
{
    AI::makeBestMove(*this);
    currentPlayerTurn = Owner::PLAYER1;
}

void Board::unselectAllHexes()
{
    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState[i].size();j++)
        {
            boardState[i][j]->setState(HexState::NOTHING);
        }
    }
}
void Board::selectHex(Hex &h)
{
    if(selectedHex != nullptr)
        selectedHex->unselect();

    selectedHex = &h;
    h.select();

    auto mapa = findPossibleMoves(h);;

    for(auto i : mapa)
    {
        i.first->setState(i.second);
    }
}
void Board::onNoMoreMoves()
{
    std::cout<<"1"<<std::endl;
    if(currentPlayerTurn == Owner::PLAYER2)
    {
        std::cout<<"w1"<<std::endl;
        fillEmptyHexes(Owner::PLAYER1);
    }
    else
    {
        std::cout<<"w2"<<std::endl;
        fillEmptyHexes(Owner::PLAYER1);
    }
    std::cout<<"2"<<std::endl;
    gameManager->onGameFinished();
}
void Board::fillEmptyHexes(Owner toFill)
{

    std::cout<<"i1"<<std::endl;
    for (int i = 0; i < boardState.size(); i++)
    {
        for (int j = 0;j<boardState[i].size();j++)
        {
            if(boardState[i][j]->getOwner() == Owner::NO_ONE) {
                boardState[i][j]->setOwner(toFill);
            }
        }
    }
    std::cout<<"i2"<<std::endl;
    scoreboard->calculateScoreboard();
}

float distance(int x1, int x2, int y1, int y2)
{
    int x = abs(x2-x1);
    int y = abs(y2-y1);

    float c = x*x + y*y;
    c = sqrt(c);

    return c;
}
std::map<Hex*,int> Board::findCloseHexes(Hex &h)
{
    auto mapa = std::map<Hex*,int>();
    mapa.clear();

    for (int i = 0; i < boardState.size(); ++i)
    {
        for (int j = 0; j < boardState[i].size(); ++j)
        {
            if(boardState[i][j] == &h)
                continue;
            float d = distance(h.getWindowPosition().x,boardState[i][j]->getWindowPosition().x,h.getWindowPosition().y,boardState[i][j]->getWindowPosition().y);

            d/=radius;
            if(d<=4)
            {
                mapa[boardState[i][j]] = (int)d;
            }
            else
            {
                boardState[i][j]->setState(HexState::NOTHING);
            }
        }
    }
    return mapa;
}


std::map<Hex*,HexState> Board::findPossibleMoves(Hex &h)
{
    auto mapa = std::map<Hex*,HexState>();
    mapa.clear();

    for (auto i : findCloseHexes(h))
    {
        if(i.first->getOwner() != Owner::NO_ONE)
            continue;
        if(i.second > 2 && i.second <= 4)
        {
            mapa[i.first] = HexState::CLOSE;
        }
        else if(i.second <= 2)
        {
            mapa[i.first] = HexState::VERY_CLOSE;
        }
    }
    return mapa;
}


void Board::drawHex(Hex& h)
{
    h.drawHex();
    h.drawOutline();
}

void Board::buildBoard(const int &save)
{
    for(int i = 0;i<5;i++)
    {
        for (int j = 0; j<i+5;j++)
        {
            if((i==4 && j==3) || (i == 3 && j == 4))
                continue;
            boardState[i].push_back(new Hex(i,j,radius,window,Owner::NO_ONE));

        }
    }
    for (int i = 0; i<4;i++)
    {
        for(int j = 0; j<8-i;j++)
        {
            if(i==0 && j == 4)
                continue;
            boardState[i+5].push_back(new Hex(i+5,j,radius,window,Owner::NO_ONE));
        }
    }


    if(save==-1)
    {
        boardState[0][0]->setOwner(Owner::PLAYER1);
        boardState[0][4]->setOwner(Owner::PLAYER2);

        boardState[4][0]->setOwner(Owner::PLAYER2);
        boardState[4][7]->setOwner(Owner::PLAYER1);

        boardState[8][0]->setOwner(Owner::PLAYER1);
        boardState[8][4]->setOwner(Owner::PLAYER2);
    }
    else
    {
        std::vector<HexInfo*> hexInfos = GameSaver::getBoardStateFromSave(save);
        for(int i = 0; i<hexInfos.size();i++)
        {
            int py = hexInfos[i]->posy;
            if((hexInfos[i]->posx == 3 || hexInfos[i]->posx == 5) && py >= 5)
                py--;
            if(hexInfos[i]->posx == 4 && py >= 3)
                py--;
            if(i==hexInfos.size()-1)
                currentPlayerTurn = hexInfos[i]->owner;
            else
                boardState[hexInfos[i]->posx][py]->setOwner(hexInfos[i]->owner);
        }

    }
}

void Board::offsetHexes()
{
    int xSize = window.getSize().x;
    int boardSize = boardState[8][0]->getWindowPosition().x - boardState[0][0]->getWindowPosition().x;
    int remainingSize = xSize - boardSize;

    int distance = boardState[0][0]->getWindowPosition().x;
    int moveDistance = remainingSize/2 - distance;


    for (int i = 0; i < boardState.size(); i++)
    {
        for (int j = 0;j<boardState[i].size();j++)
        {
            boardState[i][j]->Move(sf::Vector2<int>(moveDistance,0));
        }
    }
}

std::vector<std::vector<Hex *>>* Board::getBoardState()
{
    return &boardState;
}
Owner Board::getCurrentPlayerTurn() {
    return currentPlayerTurn;
}
Board::~Board()
{
    std::cout<<"del1"<<std::endl;
    //delete scoreboard;
    std::cout<<"del2"<<std::endl;

    //delete board states
/*    for(int i = 0; i<boardState.size();i++)
    {
        for(int j = 0; j<boardState.at(i).size();i++)
        {
            std::cout<<"board: " << boardState[i][j]->getPosX() << std::endl;
            //delete boardState.at(i).at(j);
        }
    }*/
    std::cout<<"del3"<<std::endl;
}

sf::Vector2<int> Board::getScores() {
    return scoreboard->getScore();
}
