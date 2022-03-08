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

    int placeShip(std::string input, int angle, PlayerPtr player, int turnIn)
    {
        //Get int Coordinates from "A1" "2C" "B 5" sort of input
        int x = {};
        int y = {};
        for (int i = 0; i < input.length(); ++i)
        {
            int inCode = (int)input[i];
            if(inCode >= 49 && inCode <= 56)
            {
                if (!(y && y != 0))
                {
                    y = inCode - 49;
                }
            }
            else if ((inCode >= 65 && inCode <= 72))
            {
                if (!(x && x != 0))
                {
                    x = inCode - 65;
                }
            }
            else if ((inCode >= 97 && inCode <= 104))
            {
                if (!(x && x != 0))
                {
                    x = inCode - 97;
                }
            }
        }

        //Get a pointer for a new ship
        ShipPtr currentShip = {};
        switch (turnIn)
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
        }
        
        //Check if new ship overlaps with another
        for (int i = 0; i < currentShip->shape.size(); ++i)
        {
            for (int j = 0; j < currentShip->shape[0].size(); ++j)
            {
                int checkX;
                int checkY;
                if (angle % 2 == 0)
                {
                    checkX = x + j;
                    checkY = y + i;
                }
                else
                {
                    checkX = x + i;
                    checkY = y + j;
                }
                

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
                        switch (turnIn)
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
        player->playerZoneBoard = matrixwrite::matrixWriteInt(player->playerZoneBoard, currentShip->shape, x, y, angle);
        player->playerBoard = matrixwrite::intMatrixNormalize(player->playerBoard);
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
                if (!(y && y != 0))
                {
                    y = inCode - 49;
                }
            }
            else if ((inCode >= 65 && inCode <= 72))
            {
                if (!(x && x != 0))
                {
                    x = inCode - 65;
                }
            }
            else if ((inCode >= 97 && inCode <= 104))
            {
                if (!(x && x != 0))
                {
                    x = inCode - 97;
                }
            }
        }

        //Check the State of the Targeted Square
        bool hitShip = false;
        switch (toward->playerBoard[y][x]) //X and Y were switched in every reference this point and beyond
        {
            case 0:
                //Assign a miss value to board in question
                toward->playerBoard[y][x] = 1;
                from->opponentBoard[y][x] = 1;
                break;

            case 1:
                std::cout << "You already shot at that square. It was a miss.\n";
                break;

            case 2:
                std::cout << "You already shot at that square. It was a hit.\n";
                break;

            case 3: 
                //Assign a hit value to board in question
                toward->playerBoard[y][x] = 2;
                from->opponentBoard[y][x] = 2;
                hitShip = true;
                break;
        }

        from->updateBoardStrings();
        toward->updateBoardStrings();

        //If a Ship Was Hit, Check which Ship Was Hit
        if (hitShip)
        {
            switch (toward->playerZoneBoard[y][x])
            {
                case 1:
                    ++toward->carShip->hits;

                    //Destroy Ship If it has Sustained 5 or More Hits
                    if (toward->carShip->hits >= 5)
                    {
                        toward->carShip->destr = true;

                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 sunk COM1's carrier!\n";
                        }
                        else
                        {
                            std::cout << "COM1 sunk COM2's carrier!\n";
                        }

                        return 2;

                    } else
                    {
                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 hit COM1's carrier!\n";
                        }
                        else
                        {
                            std::cout << "COM1 hit COM2's carrier!\n";
                        }
                    }

                    break;
                case 2:
                    ++toward->batShip->hits;

                    //Destroy Ship If it has Sustained 4 or More Hits
                    if (toward->batShip->hits >= 4)
                    {
                        toward->batShip->destr = true;

                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 sunk COM1's battleship!\n";
                        }
                        else
                        {
                            std::cout << "COM1 sunk COM2's battleship!\n";
                        }

                        return 2;

                    } else
                    {
                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 hit COM1's battleship!\n";
                        }
                        else
                        {
                            std::cout << "COM1 hit COM2's battleship!\n";
                        }
                    }
                    break;
                case 3:
                    ++toward->cruiShip->hits;

                    //Destroy Ship If it has Sustained 3 or More Hits
                    if (toward->cruiShip->hits >= 3)
                    {
                        toward->cruiShip->destr = true;

                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 sunk COM1's cruiser!\n";
                        }
                        else
                        {
                            std::cout << "COM1 sunk COM2's cruiser!\n";
                        }

                        return 2;

                    } else
                    {
                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 hit COM1's cruiser!\n";
                        }
                        else
                        {
                            std::cout << "COM1 hit COM2's cruiser!\n";
                        }
                    }
                    break;
                case 4:
                    ++toward->subShip->hits;

                    //Destroy Ship If it has Sustained 3 or More Hits
                    if (toward->subShip->hits >= 3)
                    {
                        toward->subShip->destr = true;

                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 sunk COM1's submarine!\n";
                        }
                        else
                        {
                            std::cout << "COM1 sunk COM2's submarine!\n";
                        }

                        return 2;

                    }else
                    {
                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 hit COM1's submarine!\n";
                        }
                        else
                        {
                            std::cout << "COM1 hit COM2's submarine!\n";
                        }
                    }
                    break;
                case 5:
                    ++toward->desShip->hits;

                    //Destroy Ship If it has Sustained 2 or More Hits
                    if (toward->desShip->hits >= 2)
                    {
                        toward->desShip->destr = true;

                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 sunk COM1's destroyer!\n";
                        }
                        else
                        {
                            std::cout << "COM1 sunk COM2's destroyer!\n";
                        }

                        return 2;

                    }else
                    {
                        //Sinking Notification
                        if (toward->id == 1)
                        {
                            std::cout << "COM2 hit COM1's destroyer!\n";
                        }
                        else
                        {
                            std::cout << "COM1 hit COM2's destroyer!\n";
                        }
                    }
                    break;

            }

            return 1;
        }



        return 0;
    }

    int stringToInt(std::string input)
    {
        for (int i = 0; i < input.size(); ++i)
        {
            switch (input[i])
            {
            case '0':
                return 0;
                break;
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            }
        }

        return 0;
    }

    void checkPlayerShips(PlayerPtr target)
    {
        if (target->batShip->destr && target->carShip->destr && target->cruiShip->destr && target->desShip->destr && target->subShip->destr)
        {
            battleshipGame::gameOver = true;
            
            if (target->id == 1)
            {
                std::cout << "COM1 won the game!\n";
            }
            else
            {
                std::cout << "COM2 won the game!\n";
            }
        }
    }

    std::string intToAlpha(int input)
    {
        int charCode = 65 + input;

        std::string ret = "";

        ret += (char)charCode;

        return ret;
    }
}
