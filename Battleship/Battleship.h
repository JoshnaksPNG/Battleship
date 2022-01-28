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

        std::vector<std::vector<int>> shape;
        int width;
        int length;

        Ship(int x, int y, int theta, std::vector<std::vector<int>> shapeIn, int widthIn, int lengthIn)
        {
            xPos = x;
            yPos = y;
            angle = theta; 

            shape = shapeIn;
            width = widthIn;
            length = lengthIn;
        }
};

//Ship Subclasses
//Battleship Subclass
class Battleship : public Ship
{
    public:
        Battleship(int xPos, int yPos, int angle) 
            : Ship(
                    xPos, 
                    yPos, 
                    angle, 
                    {
                        {1,1,1,1}
                    },
                    1, 
                    4)
        {
            
        }
};

//Cruiser Subclass
class Cruiser : public Ship
{
    public:
        Cruiser(int xPos, int yPos, int angle) 
            : Ship( xPos, 
                    yPos, 
                    angle, 
                    {
                        {1,1,1}
                    },
                    1, 
                    3)
        {

        }
};

//Submarine Subclass
class Submarine : public Ship
{
    public:
        Submarine(int xPos, int yPos, int angle) 
            : Ship( xPos, 
                    yPos, 
                    angle, 
                    {
                        {1,1,1}
                    }, 
                    1, 
                    3)
        {

        }
};

//Destroyer Subclass
class Destroyer : public Ship
{
    public:
        Destroyer(int xPos, int yPos, int angle) 
            : Ship( xPos, 
                    yPos, 
                    angle, 
                    {
                        {1,1}
                    } , 
                    1, 
                    2)
        {

        }
};

//Carrier Subclass
class Carrier : public Ship
{
    public:
        Carrier(int xPos, int yPos, int angle)
            : Ship(xPos,
                   yPos,
                   angle,
                   { {1,1,1},
                     {1,1,0} },
                   2,
                   3)
        {
        }
};

typedef std::shared_ptr<Ship> ShipPtr;

class Player
{
    public:
        //Player Score
        int score = 0;

        //Hits and Misses
        std::vector<std::vector<int>> misses = {};
        std::vector<std::vector<int>> hits = {};

        //Player Ships
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

        //Space for Player Ships
        std::shared_ptr <Battleship> batShip;
        std::shared_ptr <Cruiser> cruiShip;
        std::shared_ptr <Submarine> subShip;
        std::shared_ptr <Destroyer> desShip;
        std::shared_ptr <Carrier> carShip;

        std::string updateBoardStrings()
        {
            //Update Player Board String
            //Inital Top Row
            std::string updatedPlayerString = "  A B C D E F G H\n";

            //Update each line of the updated string
            for (int i = 0; i < 8; ++i)
            {
                std::string newRow = std::to_string(i + 1) + " ";

                //Update each character of updated line
                for (int j = 0; j < 8; ++j)
                {
                    newRow += std::to_string(playerBoard[i][j]);

                    if (j != 7)
                    {
                        newRow += " ";
                    }
                    else
                    {
                        newRow += "\n";
                    }
                }

                updatedPlayerString += newRow;

            }

            this->playerBString = updatedPlayerString;

            //Update Opponent Board String
            std::string updatedOpponentString = "  A B C D E F G H\n";

            //Update each line of the updated string
            for (int i = 0; i < 8; ++i)
            {
                std::string newRow = std::to_string(i + 1) + " ";

                //Update each character of updated line
                for (int j = 0; j < 8; ++j)
                {
                    newRow += std::to_string(opponentBoard[i][j]);

                    if (j != 7)
                    {
                        newRow += " ";
                    }
                    else
                    {
                        newRow += "\n";
                    }
                }

                updatedOpponentString += newRow;

            }

            this->opponentBString = updatedOpponentString;

            return "";
        }
};



//Namespace for Game Variables and Methods
namespace battleshipGame
{
    typedef std::shared_ptr<Player> PlayerPtr;

    extern std::vector<PlayerPtr> players;

    // ships.push_back(std::make_shared<Ship>(constructor_args...));
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

    int placeShip(std::string input, int angle, PlayerPtr player);

    std::string updateBoardString();
}
