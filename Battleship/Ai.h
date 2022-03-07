#pragma once

#include "Battleship.h"
#include <stdint.h>

namespace ai
{
    void setup(battleshipGame::PlayerPtr comPlyr);

    void move(battleshipGame::PlayerPtr comPlyr, battleshipGame::PlayerPtr plyr);


}

class PossibleCell
{
    public:
        int x;
        int y;

        PossibleCell(int xIn, int yIn)
        {
            x = xIn;
            y = yIn;
        }
};

class HitCell
{
    public:
        int x;
        int y;
        
        std::vector<PossibleCell> adjCells = {};

        HitCell(int xIn, int yIn)
        {
            x = xIn;
            y = yIn;

            //Add Horizontal Possibles
            if (y != 0)
            {
                adjCells.push_back(PossibleCell(x, y - 1));
            }
            if (y != 7)
            {
                adjCells.push_back(PossibleCell(x, y + 1));
            }

            //Add Horizontal Possibles
            if (x != 0)
            {
                adjCells.push_back(PossibleCell(x - 1, y));
            }
            if (x != 7)
            {
                adjCells.push_back(PossibleCell(x + 1, y));
            }
        }
};

class COMPlayer : public Player
{
	public:
        //Direction the COMPlayer's shot's are trending
        //u: up, d: down, l: left, r: right
		char direction = 'd';

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

        //Shot List
        std::vector<HitCell> hitList = {};

        //Random Shooting or Nah
        bool randomFire = true;

        COMPlayer() : Player(true)
        {}
};