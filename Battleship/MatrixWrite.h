#pragma once

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	int matrixWriteInt(int largeMatrix, int smallMatrix);
	bool matrixWriteBool(bool largeMatrix, bool smallMatrix);
	char matrixWriteChar(char largeMatrix, char smallMatrix);
	float matrixWriteFloat(float largeMatrix, float smallMatrix);
	double matrixWriteDouble(double largeMatrix, double smallMatrix);

}