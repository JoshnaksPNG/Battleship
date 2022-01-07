//Header Inclusion
#include "Battleship.h"
#include <vector>

//Namespace for Game Variables and Methods
namespace battleshipGame
{
    std::vector<int> score = { 0, 0 };

    bool gameOver = false;

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
}
