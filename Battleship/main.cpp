//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
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