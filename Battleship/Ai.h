#pragma once

#include "Battleship.h"

namespace ai
{
	


}

class COMPlayer : public Player
{
	public:
        //Direction the COMPlayer's shot's are trending
        //u: up, d: down, l: left, r: right
		char direction = 'n';

        //Shot Attempts
        //0: not attempted, 1: miss, 2: hit
		std::vector<std::vector<char>> attempts = 
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