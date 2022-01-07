#pragma once

//Header Inclusion
#include <iostream>
#include <string>
#include <vector>
#include <memory>

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

class Player
{
    public:
        //Player Score
        int score = 0;

        //Hits and Misses
        std::vector<std::vector<int>> misses = {};
        std::vector<std::vector<int>> hits = {};

        //Player Ships
        typedef std::unique_ptr<Ship> ShipPtr;
        std::vector<ShipPtr> ships;

        //Boards
        std::vector<std::vector<int>> playerBoard =
        {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0}
        };
        std::string playerBString;
        std::vector<std::vector<int>> opponentBoard =
        {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0}
        };
        std::string opponentBString;
};

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    typedef std::unique_ptr<Player> PlayerPtr;

    extern std::vector<int> players;

    // ships.push_back(std::make_unique<Ship>(constructor_args...));
    /*
        for (auto& pShip : ships)
        {
            pShip->Foo();
            Bar(*pShip);
        }
    */
    extern bool gameOver;

    extern std::vector<std::vector<int>> board;

    extern std::string boardString;

    extern int turn;
    
    int nextTurn();

    int setupTurn();

    int placeShip(std::string input, int angle, int player);

    std::string updateBoardString();
}
