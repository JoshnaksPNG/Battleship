#include "Ai.h"
#include"Battleship.h"
#include <stdint.h>

namespace ai
{
	void updateCongruentSpaces(battleshipGame::PlayerPtr comPlyr)
	{
		//auto *comPlyr;
		auto comPtr = dynamic_cast<COMPlayer*>(comPlyr.get());

		//Test for NULL
		if(!comPtr)
		{
			return;
		}

		//Set squares adjacent to squares containing a ship to being ship adjacent
		for (int i = 0; i < comPtr->placement.size(); ++i)
		{
			for (int j = 0; j < comPtr->placement[0].size(); ++j)
			{
				if (comPtr->placement[i][j] == 1)
				{
					if (i != 0)
					{
						if (comPtr->placement[i - 1][j] != 1 || comPtr->placement[i - 1][j] != 2)
						{
							comPtr->placement[i - 1][j] = 2;
						}
					}
					else if (i != 8)
					{
						if (comPtr->placement[i + 1][j] != 1 || comPtr->placement[i + 1][j] != 2)
						{
							comPtr->placement[i + 1][j] = 2;
						}
					}

					if (j != 0)
					{
						if (comPtr->placement[i][j - 1] != 1 || comPtr->placement[i][j - 1] != 2)
						{
							comPtr->placement[i][j - 1] = 2;
						}
					}
					else if (j != 8)
					{
						if (comPtr->placement[i][j + 1] != 1 || comPtr->placement[i][j + 1] != 2)
						{
							comPtr->placement[i][j + 1] = 2;
						}
					}
				}
			}
		}
	}

	void setup(battleshipGame::PlayerPtr comPlyr)
	{
		//Randomly Select Ship to Place on Edge
		srand(time(NULL));
		int edgeShipNum = (rand() % 4 + 1) * -1;

		//Initialize edgeShip Pointer
		int edgeShipLength;

		//Define edgeShip Pointer
		std::vector<int> remainShips =
		{
			-5,
			-4,
			-3,
			-2,
			-1
		};
		switch (edgeShipNum)
		{
			case -4:
				edgeShipLength = 4;
				remainShips.erase(remainShips.begin() + 1);
				break;
			case -3:
				edgeShipLength = 3;
				remainShips.erase(remainShips.begin() + 2);
				break;
			case -2:
				edgeShipLength = 3;
				remainShips.erase(remainShips.begin() + 3);
				break;
			case -1:
				edgeShipLength = 2;
				remainShips.erase(remainShips.begin() + 4);
				break;
			default:
				edgeShipLength = 2;
				remainShips.erase(remainShips.begin() + 4);
				break;
		}

		//Choose Edge to Place Ship On
		int placedEdge = rand() % 4;
		int edgeShipAngle = placedEdge % 2;

		int randomCoord = rand() % (8 - edgeShipLength + 1);

		std::string coordSet = "";

		char coordCode = randomCoord + 48;

		//Horizontal Ship Placement
		if (edgeShipAngle == 0) 
		{
			if (placedEdge == 0)
			{
				coordSet += battleshipGame::intToAlpha(randomCoord);
				coordSet += "1";
			}

			else
			{
				coordSet += battleshipGame::intToAlpha(randomCoord);
				coordSet += "8";
			}
		}

		//Vertical Ship Placement
		else
		{
			if (placedEdge == 1)
			{
				coordSet += "A";
				coordSet += ((char)coordCode);
			}

			else
			{
				coordSet += "H";
				coordSet += ((char)coordCode);
			}
		}

		//Place Ship
		battleshipGame::placeShip(coordSet, edgeShipAngle, comPlyr, edgeShipNum);
		updateCongruentSpaces(comPlyr);

		//Randomly Place Other Ships
		for (int i = 0; i < remainShips.size(); ++i)
		{
			//Random Coordinates



			switch (i)
			{
				case -5:
					
					break;
				case -4:

					break;
				case -3:

					break;
				case -2:

					break;
				default:

					break;
			}
		}
	}

	void move(battleshipGame::PlayerPtr comPlyr)
	{

	}


}