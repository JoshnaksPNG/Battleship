#pragma once

#include "Battleship.h"

namespace ai
{
	


}

class COMPlayer : public Player
{
	public:
		char direction;

		char attempts[8][8];

		int lastHit[2];
};