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
    battleshipGame::PlayerPtr play1 = std::make_shared<Player>(false);
    battleshipGame::PlayerPtr com1 = std::make_shared<COMPlayer>();

    //Randomize Player First Turn
    //Random Seed
    srand(time(NULL));

    //Which Player Goes First
    int firstTurn = rand() % 2 + 1;

    battleshipGame::placeShip("G2", 1, play1);
    play1->updateBoardStrings();

    cout << "\n";
    cout << play1->playerBString;
    
}