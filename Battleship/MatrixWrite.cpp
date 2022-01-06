#include "MatrixWrite.h"
#include <vector>

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	int matrixWriteInt(std::vector<std::vector<int>> largeMatrix, std::vector<std::vector<int>> smallMatrix, int inX, int inY, int inTheta, int largeWidth, int largeLength, int smallWidth, int smallLength)
	{
		//Check Dimensions
		if (smallWidth > largeWidth || smallWidth > largeLength || smallLength > largeWidth || smallLength > largeLength)
		{
			//I do not know how to throw errors in C++ :(
		}

		//Write Big Bucket
		std::vector<std::vector<int>> largeBucket = largeMatrix;

		//Boundaries for position
		if (inX < 0)
		{
			inX = 0;
		}
		if (inX >= largeWidth)
		{
			inX = (largeWidth - 1);
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeLength)
		{
			inY = (largeLength - 1);
		}

		//Rotate The Matrix
		int newSWidth;
		int newSLength;
		switch (inTheta)
		{
			case 1:
				
				break;


			case 2:
				
				break;


			case 3:
				
				break;


			default:
				
				break;
		}

		return 0;
	};

	bool matrixWriteBool(bool largeMatrix, bool smallMatrix, int inX, int inY, int inTheta, int largeWidth, int largeLength, int smallWidth, int smallLength)
	{
		return true;
	};

	char matrixWriteChar(char largeMatrix, char smallMatrix, int inX, int inY, int inTheta, int largeWidth, int largeLength, int smallWidth, int smallLength)
	{

		return '_';
	};

	float matrixWriteFloat(float largeMatrix, float smallMatrix, int inX, int inY, int inTheta, int largeWidth, int largeLength, int smallWidth, int smallLength)
	{
		return 0;
	};

	double matrixWriteDouble(double largeMatrix, double smallMatrix, int inX, int inY, int inTheta, int largeWidth, int largeLength, int smallWidth, int smallLength)
	{
		return 0;
	};

}