//Header Inclusion
#include "Battleship.h"
#include "MatrixWrite.h"
#include <vector>
#include<iostream>

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    //Players
    typedef std::shared_ptr<Player> PlayerPtr;
    std::vector<PlayerPtr> players;

    bool gameOver = false;

    int turn = -5;

    std::vector<std::vector<int>> board =
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

    std::string boardString;

    std::string updateBoardString ()
    {
        //Inital Top Row
        std::string updatedString = "  A B C D E F G H\n";

        //Update each line of the updated string
        for (int i = 0; i < 8; ++i)
        {
            std::string newRow = std::to_string(i + 1) + " ";

            //Update each character of updated line
            for (int j = 0; j < 8; ++j)
            {
                newRow += std::to_string(board[i][j]);
                
                if (j != 7)
                {
                    newRow += " ";
                }
                else
                {
                    newRow += "\n";
                }
            }

            updatedString += newRow;

        }

        boardString = updatedString;

        return "";
    }

    int nextTurn()
    {
        //Setup Turns
        if (turn < 0)
        {
            setupTurn();
        }
        return 0;
    }

    int setupTurn()
    {
        //Placing Different Ships
        switch (turn)
        {
            case -5:

                break;

            case -4:

                break;

            case -3:

                break;

            case -2:

                break;

            case -1:

                break;

            default:
                break;
        }

        ++turn;
        return 0;
    }

    int placeShip(std::string input, int angle, PlayerPtr player)
    {
        //Get int Coordinates from "A1" "2C" "B 5" sort of input
        int x = {};
        int y = {};
        for (int i = 0; i < input.length(); ++i)
        {
            int inCode = (int)input[i];
            if(inCode >= 49 && inCode <= 56)
            {
                if (!(x && x != 0))
                {
                    x = inCode - 49;
                }
            }
            else if ((inCode >= 65 && inCode <= 72))
            {
                if (!(y && y != 0))
                {
                    y = inCode - 65;
                }
            }
            else if ((inCode >= 97 && inCode <= 104))
            {
                if (!(y && y != 0))
                {
                    y = inCode - 97;
                }
            }
        }

        //Get a pointer for a new ship
        ShipPtr currentShip = {};
        switch (turn)
        {
            case -5:
                player->carShip = std::make_shared<Carrier>(x, y, angle);
                currentShip = player->carShip;
                break;

            case -4:
                player->batShip = std::make_shared<Battleship> (x, y, angle);
                currentShip = player->batShip;
                break;

            case -3:
                player->cruiShip = std::make_shared<Cruiser>(x, y, angle);
                currentShip = player->cruiShip;
                break;

            case -2:
                player->subShip = std::make_shared<Submarine>(x, y, angle);
                currentShip = player->subShip;
                break;

            case -1:
                player->desShip = std::make_shared<Destroyer>(x, y, angle);
                currentShip = player->desShip;
                break;

            default:
                return 3;
                break;
        }
        
        //Check if new ship overlaps with another
        for (int i = 0; i < currentShip->shape.size(); ++i)
        {
            for (int j = 0; j < currentShip->shape[0].size(); ++j)
            {
                int checkX = x + j;
                int checkY = y + i;

                //Return Error if ship placement goes off the board
                if ( checkY >= player->playerBoard.size() || checkX >= player->playerBoard[0].size() )
                {
                    return 1;
                }
                else
                {
                    //Return Error if ship placement overlaps with another ship
                    if (player->playerBoard[checkY][checkX] != 0)
                    {
                        switch (turn)
                        {
                            case -5:
                                player->carShip = 0;
                                break;

                            case -4:
                                player->batShip = 0;
                                break;

                            case -3:
                                player->cruiShip = 0;
                                break;

                            case -2:
                                player->subShip = 0;
                                break;

                            case -1:
                                player->desShip = 0;
                                break;

                            default:
                                break;
                        }

                        return 2;
                    }
                }
            }
        }

        //Place Ship and Add to Player's Ship List
        player->ships.push_back(currentShip);

        //Add ship to Player's Ship Board
        player->playerBoard = matrixwrite::matrixWriteInt(player->playerBoard, currentShip->shape, x, y, angle);
        player->updateBoardStrings();

        return 0;
    }

    //Method to Shoot At Coordinate
    int makeShot(std::string coords, battleshipGame::PlayerPtr from, battleshipGame::PlayerPtr toward)
    {
        //Coordinate Variables
        int x = {};
        int y = {};

        //Get Coordinates from String
        for (int i = 0; i < coords.length(); ++i)
        {
            int inCode = (int)coords[i];
            if (inCode >= 49 && inCode <= 56)
            {
                if (!(x && x != 0))
                {
                    x = inCode - 49;
                }
            }
            else if ((inCode >= 65 && inCode <= 72))
            {
                if (!(y && y != 0))
                {
                    y = inCode - 65;
                }
            }
            else if ((inCode >= 97 && inCode <= 104))
            {
                if (!(y && y != 0))
                {
                    y = inCode - 97;
                }
            }
        }

        //

        return 0;
    }
}
