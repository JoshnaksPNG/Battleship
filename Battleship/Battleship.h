#pragma once

//Header Inclusion
#include <iostream>
#include <string>
#include <vector>

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
        std::vector<std::vector<char>> shape = { { 'O', 'O', 'O', 'O' } };
        int width = 1;
        int length = 4;
};

//Cruiser Subclass
class Cruiser : public Ship
{
    public:
        std::vector<std::vector<char>> shape = { { 'O', 'O', 'O' } };
        int width = 1;
        int length = 3;
};

//Submarine Subclass
class Submarine : public Ship
{
    public:
        std::vector<std::vector<char>> shape = { { 'O', 'O', 'O' } };
        int width = 1;
        int length = 3;
};

//Destroyer Subclass
class Destroyer : public Ship
{
    public:
        std::vector<std::vector<char>> shape = { { 'O', 'O' } };
        int width = 1;
        int length = 2;
};

//Carrier Subclass
class Carrier : public Ship
{
    public:
        std::vector<std::vector<char>> shape = { { 'O', 'O', 'O' } , {'O', 'O', '_'} };
        int width = 1;
        int length = 3;
};

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    extern std::vector<int> score;

    extern bool gameOver;

    extern std::vector<std::vector<char>> board;

    extern std::string boardString;

    std::string updateBoardString();
}
