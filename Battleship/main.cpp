//Header Inclusion
#include "Battleship.h"
using namespace std;


//Main Loop
int main()
{
    battleshipGame::updateBoardString();
    cout << battleshipGame::boardString;

    while (!battleshipGame::gameOver)
    {
        battleshipGame::gameOver = true;
    }
}