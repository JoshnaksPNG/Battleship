#include "Ai.h"
#include"Battleship.h"
#include <stdint.h>
#include <chrono>

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

		//Set squares containing a ship to containing a ship
		for (int i = 0; i < comPtr->placement.size(); ++i)
		{
			for (int j = 0; j < comPtr->placement[0].size(); ++j)
			{
				if (comPtr->playerZoneBoard[i][j] != 0)
				{
					comPtr->placement[i][j] = 1;
				}
			}
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
		//Cast comPlyr to a COMPlayerPointer
		auto comPtr = dynamic_cast<COMPlayer*>(comPlyr.get());

		//Test for NULL
		if (!comPtr)
		{
			return;
		}

		srand(time(NULL));
		bool complete = false;

		//Was going to reset board if placing took too long, but I'm not going to worry about that right now
		while (!complete)
		{
			//Randomly Select Ship to Place on Edge
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
			while (remainShips.size() > 0)
			{
				std::vector<std::vector<int>> checkShape = {};

				bool isPlaced = false;
				while (!isPlaced)
				{
					//Random Rotation
					int r = rand() % 4;
					switch (remainShips[0])
					{
					case -5:

						switch (r)
						{
						case 1:
							checkShape =
							{
								{1,1},
								{1,1},
								{0,1}
							};


							break;
						case 2:
							checkShape =
							{
								{0,1,1},
								{1,1,1}
							};
							break;
						case 3:
							checkShape =
							{
								{1,0},
								{1,1},
								{1,1}
							};
							break;
						default:
							checkShape =
							{
								{1,1,1},
								{1,1,0}
							};
							break;
						}

						break;
					case -4:
						if (r % 2 == 0)
						{
							checkShape =
							{
								{1,1,1,1}
							};
						}
						else
						{
							checkShape =
							{
								{1},
								{1},
								{1},
								{1}
							};
						}
						break;
					case -3:
						if (r % 2 == 0)
						{
							checkShape =
							{
								{1,1,1}
							};
						}
						else
						{
							checkShape =
							{
								{1},
								{1},
								{1}
							};
						}
						break;
					case -2:
						if (r % 2 == 0)
						{
							checkShape =
							{
								{1,1,1}
							};
						}
						else
						{
							checkShape =
							{
								{1},
								{1},
								{1}
							};
						}
						break;
					default:
						if (r % 2 == 0)
						{
							checkShape =
							{
								{1,1}
							};
						}
						else
						{
							checkShape =
							{
								{1},
								{1}
							};
						}
						break;
					}

					//Random Coordinates
					int x = rand() % (9 - checkShape[0].size());
					int y = rand() % (9 - checkShape.size());

					std::string coords = "  " + battleshipGame::intToAlpha(x) + std::to_string(y);
					int placementCheck = battleshipGame::placeShip(coords, r, comPlyr, remainShips[0]);

					if (placementCheck == 0) //Thought changing this to == 0 fixed it, it did not
					{
						isPlaced = true;
						remainShips.erase(remainShips.begin());
					}

					if (remainShips.size() == 0)
					{
						complete = true;
					}
				}
			}
		}
	}

	void move(battleshipGame::PlayerPtr comPlyr, battleshipGame::PlayerPtr plyr)
	{
		auto comPlyra = dynamic_cast<COMPlayer*>(comPlyr.get());

		int x;
		int y;

		//Random Starting Shot
		if (comPlyra->randomFire)
		{
			bool clearSpot = false;
			while (!clearSpot)
			{
				x = rand() % (8);
				y = rand() % (8);

				if ((x + y) % 2 == 0)
				{
					if (comPlyra->attempts[y][x] == 0)
					{
						clearSpot = true;
						break;
					}
				}
			}
			
		}
		//Algorithmic Shooting
		else
		{
			//shoot at each adjacent cell
			bool clearSpot = false;
			while (!clearSpot)
			{
				x = comPlyra->hitList[0].adjCells[0].x;
				y = comPlyra->hitList[0].adjCells[0].y;
				comPlyra->hitList[0].adjCells.erase(comPlyra->hitList[0].adjCells.begin());

				if (comPlyra->attempts[y][x] == 0)
				{
					clearSpot = true;
				}

				//erase hitcell if all surrounding cells have been shot at
				if (comPlyra->hitList.size() != 0)
				{
					if (comPlyra->hitList[0].adjCells.size() == 0)
					{
						comPlyra->hitList.erase(comPlyra->hitList.begin());

						if (comPlyra->hitList.size() == 0)
						{
							comPlyra->randomFire = true;
							break;
						}
					}
				}
			}
		}

		//Put together coord string
		std::string coords = "" + battleshipGame::intToAlpha(x) + std::to_string(y + 1);

		std::cout << "COM shot at ";
		std::cout << coords;
		std::cout << "\n\n";

		int shotAttmpt = battleshipGame::makeShot(coords, comPlyr, plyr);

		//Update attempts
		comPlyra->attempts[y][x] = shotAttmpt;

		//Add Another Cell if a hit was returned
		if (shotAttmpt == 2 || shotAttmpt == 1)
		{
			comPlyra->hitList.push_back(HitCell(x, y));
			comPlyra->randomFire = false;
		}

		//Turn on Random Fire if No More Connected Cells
		if (comPlyra->hitList.size() == 0)
		{
			comPlyra->randomFire = true;
		}
	}

}