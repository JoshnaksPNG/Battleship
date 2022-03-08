//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
#include "MatrixWrite.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdint.h>

using namespace std;

//Main Loop
int main()
{
    //Define 2 COMPlayers
    battleshipGame::PlayerPtr com1 = std::make_shared<COMPlayer>(1);
    battleshipGame::PlayerPtr com2 = std::make_shared<COMPlayer>(2);
    auto com1a = dynamic_cast<COMPlayer*>(com1.get());
    auto com2a = dynamic_cast<COMPlayer*>(com2.get());

    //Randomize Player First Turn
    //Random Seed
    srand(time(NULL));

    //Which Player Goes First
    int firstTurn = rand() % 2 + 1;
    int turns = 0;

    ai::setup(com1);
    ai::setup(com2);

    com1->updateBoardStrings();
    com2->updateBoardStrings();

    battleshipGame::turn = 0;

    //Game Loop
    while (!battleshipGame::gameOver)
    {
        //COM2 Turn
        if ((turns + firstTurn) % 2 == 0)
        {
            ai::move(com2, com1);

            battleshipGame::checkPlayerShips(com1);
            ++turns;
        }
        //COM1 Turn
        else
        {
            ai::move(com1, com2);

            battleshipGame::checkPlayerShips(com2);
            ++turns;
        }

        if (turns % 2 == 0)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCOM1:\n";
            cout << com1->playerBString;
            cout << "\n-----------------\n\nCOM2:\n";
            cout << com2->playerBString;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        
    }
}