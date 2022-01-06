#pragma once
#include <vector>

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	std::vector<std::vector<int>> matrixWriteInt(std::vector<std::vector<int>> largeMatrix, std::vector<std::vector<int>> smallMatrix, int inX, int inY, int inTheta);
	bool matrixWriteBool(bool largeMatrix, bool smallMatrix);
	char matrixWriteChar(char largeMatrix, char smallMatrix);
	float matrixWriteFloat(float largeMatrix, float smallMatrix);
	double matrixWriteDouble(double largeMatrix, double smallMatrix);

}