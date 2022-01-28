//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
#include "MatrixWrite.h"
#include <vector>

using namespace std;

//Main Loop
int main()
{
    Battleship ship(3, 3, 1);

    battleshipGame::PlayerPtr pme = std::make_shared<Player>();

    battleshipGame::placeShip("C1", 0, pme);
    /*
    battleshipGame::board = matrixwrite::matrixWriteInt(battleshipGame::board, ship.shape, ship.xPos, ship.yPos, ship.angle);

    battleshipGame::updateBoardString();
    cout << battleshipGame::boardString;*/
}