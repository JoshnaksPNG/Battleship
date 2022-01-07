//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
#include "MatrixWrite.h"
using namespace std;

//Main Loop
int main()
{
    Battleship ship(3, 3, 1);

    battleshipGame::board = matrixwrite::matrixWriteInt(battleshipGame::board, ship.shape, ship.xPos, ship.yPos, ship.angle);

    battleshipGame::updateBoardString();
    cout << battleshipGame::boardString;
}