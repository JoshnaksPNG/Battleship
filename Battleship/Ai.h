#pragma once

#include "Battleship.h"
#include <stdint.h>

namespace ai
{
    void setup(battleshipGame::PlayerPtr comPlyr);

    void move(battleshipGame::PlayerPtr comPlyr);


}

class COMPlayer : public Player
{
	public:
        //Direction the COMPlayer's shot's are trending
        //u: up, d: down, l: left, r: right
		char direction = 'n';

        //Shot Attempts
        //0: not attempted, 1: miss, 2: hit
		std::vector<std::vector<int>> attempts = 
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

        //Placed ships
        //0: Empty Square, 1: Ship Placed, 2: Ship Adjacent
        std::vector<std::vector<int>> placement =
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

        //The Last Hit That the COM Made
		std::vector<int> lastHit = { -1, -1};

        //The Last Shot That the COM Made
        std::vector<int> lastShot = { -1, -1 };

        COMPlayer() : Player(true)
        {}
};