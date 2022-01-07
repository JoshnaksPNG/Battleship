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
        Battleship(int xPos, int yPos, int angle) : Ship(xPos, yPos, angle)
        {
            
        }

        std::vector<std::vector<int>> shape =
        {
            {1,1,1,1}
        };
        int width = 1;
        int length = 4;
};

//Cruiser Subclass
class Cruiser : public Ship
{
    public:
        Cruiser(int xPos, int yPos, int angle) : Ship(xPos, yPos, angle)
        {

        }

        std::vector<std::vector<int>> shape = 
        { 
            {1,1,1} 
        };
        int width = 1;
        int length = 3;
};

//Submarine Subclass
class Submarine : public Ship
{
    public:
        Submarine(int xPos, int yPos, int angle) : Ship(xPos, yPos, angle)
        {

        }

        std::vector<std::vector<int>> shape = 
        { 
            {1,1,1} 
        };
        int width = 1;
        int length = 3;
};

//Destroyer Subclass
class Destroyer : public Ship
{
    public:
        Destroyer(int xPos, int yPos, int angle) : Ship(xPos, yPos, angle)
        {

        }

        std::vector<std::vector<int>> shape = 
        { 
            {1,1} 
        };
        int width = 1;
        int length = 2;
};

//Carrier Subclass
class Carrier : public Ship
{
    public:
        Carrier(int xPos, int yPos, int angle) : Ship(xPos, yPos, angle)
        {

        }

        std::vector<std::vector<int>> shape = 
        { 
            {1,1,1}, 
            {1,1,0} 
        };
        int width = 1;
        int length = 3;
};

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    extern std::vector<int> score;

    extern bool gameOver;

    extern std::vector<std::vector<int>> board;

    extern std::string boardString;

    std::string updateBoardString();
}
