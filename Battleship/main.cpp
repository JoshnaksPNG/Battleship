//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
#include "MatrixWrite.h"
#include <vector>
#include <iostream>

using namespace std;

//Main Loop
int main()
{
    //Define Players
    battleshipGame::PlayerPtr play1 = std::make_shared<Player>();
    battleshipGame::PlayerPtr com1 = std::make_shared<COMPlayer>();

    //Randomize Player First Turn
    //Random Seed
    srand(time(NULL));

    //Which Player Goes First
    int firstTurn = rand() % 2 + 1;

    Battleship ship(3, 3, 1);

    battleshipGame::PlayerPtr pme = std::make_shared<Player>();

    battleshipGame::placeShip("C1", 0, pme);
    

    
}