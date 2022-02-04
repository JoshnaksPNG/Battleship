#pragma once
#include <vector>
#include <iostream>
#include <stdint.h>

namespace matrixwrite
{
	//Write a vector or matrix onto a matrix
	std::vector<std::vector<int>> matrixWriteInt(std::vector<std::vector<int>> largeMatrix, std::vector<std::vector<int>> smallMatrix, int inX, int inY, int inTheta);
	std::vector<std::vector<bool>> matrixWriteBool(std::vector<std::vector<bool>> largeMatrix, std::vector<std::vector<bool>> smallMatrix, int inX, int inY, int inTheta);
	std::vector<std::vector<char>> matrixWriteChar(std::vector<std::vector<char>> largeMatrix, std::vector<std::vector<char>> smallMatrix, int inX, int inY, int inTheta);
	std::vector<std::vector<float>> matrixWriteFloat(std::vector<std::vector<float>> largeMatrix, std::vector<std::vector<float>> smallMatrix, int inX, int inY, int inTheta);
	std::vector<std::vector<double>> matrixWriteDouble(std::vector<std::vector<double>> largeMatrix, std::vector<std::vector<double>> smallMatrix, int inX, int inY, int inTheta);

	//Change all non-zero elements to 3
	std::vector<std::vector<int>> intMatrixNormalize(std::vector<std::vector<int>> largeMatrix);
}