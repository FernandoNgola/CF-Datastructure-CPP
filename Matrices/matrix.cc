#include "matrix.h"
#include <iostream>

Matrix::Matrix()
{
	size = 4;
	InitializeArray();
}

Matrix::Matrix(int size)
{
	setN(size);
	InitializeArray();
}

void Matrix::set(int x, int y, int value)
{
	if (x == y)
	{
		A[y - 1] = value;
	}
}

int Matrix::get(int x, int y)
{
	if (x == y)
	{
		return A[x - 1];
	}
	return 0;
}

void Matrix::display()
{

	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (i == j)
			{
				std::cout << A[i] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
}
void Matrix::setN(int n)
{
	this->size = n;
}
Matrix::~Matrix() {}