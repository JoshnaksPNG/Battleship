#include "MatrixWrite.h"
#include <vector>
#include <iostream>
#include <stdint.h>

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	std::vector<std::vector<int>> matrixWriteInt(std::vector<std::vector<int>> largeMatrix, std::vector<std::vector<int>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Correct inTheta
		if (inTheta != 1 && inTheta != 2 && inTheta != 3)
		{
			inTheta = 0;
		}

		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<int>> largeBucket = largeMatrix;

		//Rotated Small Matrix Dimensions
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
			case 1:
				newSWidth = smallMatrix.size();
				newSLength = smallMatrix[0].size();
				break;


			case 2:
				newSWidth = smallMatrix[0].size();
				newSLength = smallMatrix.size();
				break;


			case 3:
				newSWidth = smallMatrix.size();
				newSLength = smallMatrix[0].size();
				break;


			default:
				newSWidth = smallMatrix[0].size();
				newSLength = smallMatrix.size();
				break;
		}

		//Rotated Matrix Bucket
		std::vector<std::vector<int>> smallBucket = {};
		for (int i = 0; i < newSLength; ++i)
		{
			smallBucket.push_back({});
			for (int j = 0; j < newSWidth; ++j)
			{
				smallBucket[i].push_back(0);
			}
		}

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - smallBucket[0].size());
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - smallBucket.size());
		}

		//Write to Rotated Bucket
		switch (inTheta)
		{
			case 1:
				//Flip that sucker sideways (new Y = old x; new x = reverse Y)
				for (int i = 0; i < newSLength; ++i)
				{
					for (int j = 0; j < newSWidth; ++j)
					{
						smallBucket[i][j] = smallMatrix[(newSWidth - j) - 1][i];
					}
				}
				break;


			case 2:
				//Flip that sucker upside Down
				for (int i = 0; i < newSLength; ++i)
				{
					for (int j = 0; j < newSWidth; ++j)
					{
						smallBucket[i][j] = smallMatrix[(newSLength - i) - 1][(newSWidth - j) - 1];
					}
				}
				break;


			case 3:
				//Flip that sucker sideways the other way (new x = old y?; new y = reverse x?)
				for (int i = 0; i < newSLength; ++i)
				{
					for (int j = 0; j < newSWidth; ++j)
					{
						smallBucket[i][j] = smallMatrix[j][(newSLength - i) - 1];
					}
				}
				break;


			default:
				smallBucket = smallMatrix;
				break;
		}

		//Write Small onto Large
		for (int i = 0; i < smallBucket.size(); ++i)
		{
			for (int j = 0; j < smallBucket[0].size(); ++j)
			{
				largeBucket[i + inY][j + inX] = smallBucket[i][j];
			}
		}

		return largeBucket;
	};

	std::vector<std::vector<bool>> matrixWriteBool(std::vector<std::vector<bool>> largeMatrix, std::vector<std::vector<bool>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Correct inTheta
		if (inTheta != 1 && inTheta != 2 && inTheta != 3)
		{
			inTheta = 0;
		}

		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<bool>> largeBucket = largeMatrix;

		//Rotated Small Matrix Dimensions
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
		case 1:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		case 2:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;


		case 3:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		default:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;
		}

		//Rotated Matrix Bucket
		std::vector<std::vector<bool>> smallBucket = {};
		for (int i = 0; i < newSLength; ++i)
		{
			smallBucket.push_back({});
			for (int j = 0; j < newSWidth; ++j)
			{
				smallBucket[i].push_back(0);
			}
		}

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - smallBucket[0].size());
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - smallBucket.size());
		}

		//Write to Rotated Bucket
		switch (inTheta)
		{
		case 1:
			//Flip that sucker sideways (new Y = old x; new x = reverse Y)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSWidth - j) - 1][i];
				}
			}
			break;


		case 2:
			//Flip that sucker upside Down
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSLength - i) - 1][(newSWidth - j) - 1];
				}
			}
			break;


		case 3:
			//Flip that sucker sideways the other way (new x = old y?; new y = reverse x?)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[j][(newSLength - i) - 1];
				}
			}
			break;


		default:
			smallBucket = smallMatrix;
			break;
		}

		//Write Small onto Large
		for (int i = 0; i < smallBucket.size(); ++i)
		{
			for (int j = 0; j < smallBucket[0].size(); ++j)
			{
				largeBucket[i + inY][j + inX] = smallBucket[i][j];
			}
		}

		return largeBucket;
	};

	std::vector<std::vector<char>> matrixWriteChar(std::vector<std::vector<char>> largeMatrix, std::vector<std::vector<char>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Correct inTheta
		if (inTheta != 1 && inTheta != 2 && inTheta != 3)
		{
			inTheta = 0;
		}

		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<char>> largeBucket = largeMatrix;

		//Rotated Small Matrix Dimensions
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
		case 1:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		case 2:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;


		case 3:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		default:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;
		}

		//Rotated Matrix Bucket
		std::vector<std::vector<char>> smallBucket = {};
		for (int i = 0; i < newSLength; ++i)
		{
			smallBucket.push_back({});
			for (int j = 0; j < newSWidth; ++j)
			{
				smallBucket[i].push_back(0);
			}
		}

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - smallBucket[0].size());
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - smallBucket.size());
		}

		//Write to Rotated Bucket
		switch (inTheta)
		{
		case 1:
			//Flip that sucker sideways (new Y = old x; new x = reverse Y)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSWidth - j) - 1][i];
				}
			}
			break;


		case 2:
			//Flip that sucker upside Down
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSLength - i) - 1][(newSWidth - j) - 1];
				}
			}
			break;


		case 3:
			//Flip that sucker sideways the other way (new x = old y?; new y = reverse x?)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[j][(newSLength - i) - 1];
				}
			}
			break;


		default:
			smallBucket = smallMatrix;
			break;
		}

		//Write Small onto Large
		for (int i = 0; i < smallBucket.size(); ++i)
		{
			for (int j = 0; j < smallBucket[0].size(); ++j)
			{
				largeBucket[i + inY][j + inX] = smallBucket[i][j];
			}
		}

		return largeBucket;
	};

	std::vector<std::vector<float>> matrixWriteFloat(std::vector<std::vector<float>> largeMatrix, std::vector<std::vector<float>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Correct inTheta
		if (inTheta != 1 && inTheta != 2 && inTheta != 3)
		{
			inTheta = 0;
		}

		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<float>> largeBucket = largeMatrix;

		//Rotated Small Matrix Dimensions
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
		case 1:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		case 2:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;


		case 3:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		default:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;
		}

		//Rotated Matrix Bucket
		std::vector<std::vector<float>> smallBucket = {};
		for (int i = 0; i < newSLength; ++i)
		{
			smallBucket.push_back({});
			for (int j = 0; j < newSWidth; ++j)
			{
				smallBucket[i].push_back(0);
			}
		}

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - smallBucket[0].size());
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - smallBucket.size());
		}

		//Write to Rotated Bucket
		switch (inTheta)
		{
		case 1:
			//Flip that sucker sideways (new Y = old x; new x = reverse Y)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSWidth - j) - 1][i];
				}
			}
			break;


		case 2:
			//Flip that sucker upside Down
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSLength - i) - 1][(newSWidth - j) - 1];
				}
			}
			break;


		case 3:
			//Flip that sucker sideways the other way (new x = old y?; new y = reverse x?)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[j][(newSLength - i) - 1];
				}
			}
			break;


		default:
			smallBucket = smallMatrix;
			break;
		}

		//Write Small onto Large
		for (int i = 0; i < smallBucket.size(); ++i)
		{
			for (int j = 0; j < smallBucket[0].size(); ++j)
			{
				largeBucket[i + inY][j + inX] = smallBucket[i][j];
			}
		}

		return largeBucket;
	};

	std::vector<std::vector<double>> matrixWriteDouble(std::vector<std::vector<double>> largeMatrix, std::vector<std::vector<double>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Correct inTheta
		if (inTheta != 1 && inTheta != 2 && inTheta != 3)
		{
			inTheta = 0;
		}

		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<double>> largeBucket = largeMatrix;

		//Rotated Small Matrix Dimensions
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
		case 1:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		case 2:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;


		case 3:
			newSWidth = smallMatrix.size();
			newSLength = smallMatrix[0].size();
			break;


		default:
			newSWidth = smallMatrix[0].size();
			newSLength = smallMatrix.size();
			break;
		}

		//Rotated Matrix Bucket
		std::vector<std::vector<double>> smallBucket = {};
		for (int i = 0; i < newSLength; ++i)
		{
			smallBucket.push_back({});
			for (int j = 0; j < newSWidth; ++j)
			{
				smallBucket[i].push_back(0);
			}
		}

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - smallBucket[0].size());
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - smallBucket.size());
		}

		//Write to Rotated Bucket
		switch (inTheta)
		{
		case 1:
			//Flip that sucker sideways (new Y = old x; new x = reverse Y)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSWidth - j) - 1][i];
				}
			}
			break;


		case 2:
			//Flip that sucker upside Down
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[(newSLength - i) - 1][(newSWidth - j) - 1];
				}
			}
			break;


		case 3:
			//Flip that sucker sideways the other way (new x = old y?; new y = reverse x?)
			for (int i = 0; i < newSLength; ++i)
			{
				for (int j = 0; j < newSWidth; ++j)
				{
					smallBucket[i][j] = smallMatrix[j][(newSLength - i) - 1];
				}
			}
			break;


		default:
			smallBucket = smallMatrix;
			break;
		}

		//Write Small onto Large
		for (int i = 0; i < smallBucket.size(); ++i)
		{
			for (int j = 0; j < smallBucket[0].size(); ++j)
			{
				largeBucket[i + inY][j + inX] = smallBucket[i][j];
			}
		}

		return largeBucket;
	};

	//Change all non-zero elements to 3
	std::vector<std::vector<int>> intMatrixNormalize(std::vector<std::vector<int>> largeMatrix)
	{
		std::vector<std::vector<int>> outMatrix = {};

		for (int i = 0; i < largeMatrix.size(); ++i)
		{
			outMatrix.push_back({});
			for (int j = 0; j < largeMatrix[i].size(); ++j)
			{
				if (largeMatrix[i][j] == 0)
				{
					outMatrix[i].push_back(0);
				}
				else
				{
					outMatrix[i].push_back(3);
				}
			}
		}

		return outMatrix;
	}
}