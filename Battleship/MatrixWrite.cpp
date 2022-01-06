#include "MatrixWrite.h"
#include <vector>

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	std::vector<std::vector<int>> matrixWriteInt(std::vector<std::vector<int>> largeMatrix, std::vector<std::vector<int>> smallMatrix, int inX, int inY, int inTheta)
	{
		//Check Dimensions
		if (smallMatrix.size() > largeMatrix.size() || smallMatrix.size() > largeMatrix[0].size() || smallMatrix[0].size() > largeMatrix.size() || smallMatrix[0].size() > largeMatrix[0].size())
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
		if (inX >= largeMatrix[0].size())
		{
			inX = (largeMatrix[0].size() - 1);
		}
		if (inY < 0)
		{
			inY = 0;
		}
		if (inY >= largeMatrix.size())
		{
			inY = (largeMatrix.size() - 1);
		}

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
		std::vector<std::vector<int>> smallBucket = smallMatrix;

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

		return smallBucket;
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