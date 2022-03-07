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
    //Define Players
    battleshipGame::PlayerPtr play1 = std::make_shared<Player>(false);
    battleshipGame::PlayerPtr com1 = std::make_shared<COMPlayer>();
    auto com1a = dynamic_cast<COMPlayer*>(com1.get());

    //Randomize Player First Turn
    //Random Seed
    srand(time(NULL));

    //Which Player Goes First
    int firstTurn = rand() % 2 + 1;
    int turns = 0;

    ai::setup(com1);
    play1->updateBoardStrings();
    //std::cout << play1->zoneBString;

    com1->updateBoardStrings();

    //Game Loop
    while (!battleshipGame::gameOver)
    {
        //Placing Ships
        if (battleshipGame::turn < 0)
        {
            std::cout << "Please choose where to place your ";

            switch (battleshipGame::turn)
            {
                case -5:
                    std::cout << "carrier";
                    break;
                case -4:
                    std::cout << "battleship";
                    break;
                case -3:
                    std::cout << "cruiser";
                    break;
                case -2:
                    std::cout << "submarine";
                    break;
                case -1:
                    std::cout << "destroyer";
                    break;
            }

            bool shipPlaced = false;
            while (!shipPlaced)
            {
                std::cout << ". Use the format of LetterNumber (i.e. A1, H8, etc.)";

                std::cout << "\n";
                string coordInput;
                cin >> coordInput;

                std::cout << "Please choose a degree of rotation. 0, 1, 2, 3. Any digit or character outside of 0-3 will default to 0.";

                std::cout << "\n";
                std::string angleInput;
                cin >> angleInput;

                int placedOut = battleshipGame::placeShip(coordInput, battleshipGame::stringToInt(angleInput), play1, battleshipGame::turn);

                if (placedOut == 0)
                {
                    shipPlaced = true;
                }
            }

            ++battleshipGame::turn;
            play1->updateBoardStrings();
            std::cout << play1->zoneBString;
            std::cout << "-----------------\n";
        }

        //Post-setup Game
        else
        {
            //Player Turn
            if ((turns + firstTurn) % 2 == 0)
            {
                std::cout << "Where do you want to aim for? Same LetterNumber format.";

                std::cout << "\n";
                std::string coordInput;
                std::cin >> coordInput;

                std::cout << "\n\n\n\n\n\n\n\n\n";

                battleshipGame::makeShot(coordInput, play1, com1);

                battleshipGame::checkPlayerShips(com1);

                ++turns;
            }
            //COM Player Turn
            else
            {
                ai::move(com1, play1);

                battleshipGame::checkPlayerShips(play1);
                ++turns;

                std::cout << play1->playerBString;
                std::cout << "\n";
                std::cout << play1->opponentBString;
            }
        }

        
    }
}