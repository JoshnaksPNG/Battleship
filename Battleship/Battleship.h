#pragma once

//Header Inclusion
#include <iostream>
#include <string>

//Ship Class
class Ship 
{
    public:
        int xPos;
        int yPos;
        int angle;

        Ship(int x, int y, int theta)
        {
            xPos = x;
            yPos = y;
            angle = theta; 
        }
};

//Ship Subclasses
//Battleship Subclass
class Battleship : public Ship
{
    public:
        char shape[1][4] = { { 'O', 'O', 'O', 'O' } };
        int width = 1;
        int length = 4;
};

//Cruiser Subclass
class Cruiser : public Ship
{
    public:
        char shape[1][3] = { { 'O', 'O', 'O' } };
        int width = 1;
        int length = 3;
};

//Submarine Subclass
class Submarine : public Ship
{
    public:
        char shape[1][3] = { { 'O', 'O', 'O' } };
        int width = 1;
        int length = 3;
};

//Destroyer Subclass
class Destroyer : public Ship
{
    public:
        char shape[1][2] = { { 'O', 'O' } };
        int width = 1;
        int length = 2;
};

//Carrier Subclass
class Carrier : public Ship
{
    public:
        char shape[2][3] = { { 'O', 'O', 'O' } , {'O', 'O', '_'} };
        int width = 1;
        int length = 3;
};

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    extern int score[2];

    extern bool gameOver;

    extern char board[8][8];

    extern std::string boardString;

    std::string updateBoardString();
}
