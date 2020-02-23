#include <iostream>
#include "matrix.h"

int main(void) {
	element mat[HEIGHT][WIDTH] = { {1,1,1,1,-2},{-2,-1,-2,29},{1,3,-1,-1,-16},{1,-2,3,2,11} };
	
	Matrix matrix(mat);
	matrix.Display();
	matrix.Gaussian_Method();
	matrix.Display();

	return 0;

}
