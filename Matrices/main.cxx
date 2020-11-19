#include "matrix.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Matrix mtr(6);
	mtr.set(1, 1, 3);
	mtr.set(2, 2, 5);
	mtr.set(3, 3, 7);
	mtr.set(4, 4, 9);
	mtr.set(5, 5, 11);
	mtr.set(6, 6, 13);
	std::cout << mtr.get(2, 2) << std::endl;
	mtr.display();
	return 0;
}