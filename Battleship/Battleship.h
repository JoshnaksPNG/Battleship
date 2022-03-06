#pragma once

//Header Inclusion
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdint.h>

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

        int hits = 0;
        bool destr = false;

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
                        {2,2,2,2}
                    },
                    1, 
                    4)
        {}
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
                        {3,3,3}
                    },
                    1, 
                    3)
        {}
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
                        {4,4,4}
                    }, 
                    1, 
                    3)
        {}
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
                        {5,5}
                    } , 
                    1, 
                    2)
        {}
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
        {}
};

namespace battleshipGame
{
    typedef std::shared_ptr<Ship> ShipPtr;
}

class Player
{
    public:
        //COM Bool
        bool com;

        //Player Score
        int score = 0;

        //Hits and Misses
        std::vector<std::vector<int>> misses = {};
        std::vector<std::vector<int>> hits = {};

        //Player Ships
        std::vector<battleshipGame::ShipPtr> ships;

        //Boards
        //0: not attempted, 1: miss, 2: hit, 3: Ship Location
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

        //Ship Zones
        //1: Carrier, 2: Battleship, 3: Cuiser, 4: Submarine, 5: Destroyer
        std::vector<std::vector<int>> playerZoneBoard =
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
        std::string zoneBString;

        //0: not attempted, 1: miss, 2: hit
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

        //Method to Update The Board Strings
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

            //Update Player Board String
            //Inital Top Row
            std::string updatedZoneString = "  A B C D E F G H\n";

            //Update each line of the updated string
            for (int i = 0; i < 8; ++i)
            {
                std::string newRow = std::to_string(i + 1) + " ";

                //Update each character of updated line
                for (int j = 0; j < 8; ++j)
                {
                    newRow += std::to_string(playerZoneBoard[i][j]);

                    if (j != 7)
                    {
                        newRow += " ";
                    }
                    else
                    {
                        newRow += "\n";
                    }
                }

                updatedZoneString += newRow;

            }

            this->zoneBString = updatedZoneString;

            return "";
        }

        //Constructor
        Player(bool comIn)
        {
            com = comIn;
        }

        //I don't know what this does, but it makes the error go bye-bye
        virtual ~Player() = default;
};



//Namespace for Game Variables and Methods
namespace battleshipGame
{
    typedef std::shared_ptr<Player> PlayerPtr;

    extern std::vector<PlayerPtr> players;

    extern bool gameOver;

    extern std::vector<std::vector<int>> board;

    extern std::string boardString;

    extern int turn;
    
    int nextTurn();

    int setupTurn();

    int placeShip(std::string input, int angle, PlayerPtr player, int turnIn);

    std::string updateBoardString();

    int makeShot(std::string coords, battleshipGame::PlayerPtr from, battleshipGame::PlayerPtr toward);

    int stringToInt(std::string input);

    void checkPlayerShips(PlayerPtr target);

    std::string intToAlpha(int input);
}
