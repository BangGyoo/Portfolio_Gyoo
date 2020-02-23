#include <iostream>
#include "matrix.h"

//extern element (*matrix)[WIDTH];

Matrix::Matrix(element(*matrix_Args)[WIDTH]) {
	matrix = matrix_Args;
	
}
mat_element (Matrix::Gaussian_Method()){

	register int i; register int j;
	int loop_Global;

	element division;
	for (loop_Global = 0; loop_Global < HEIGHT; loop_Global++) {
		for (i = loop_Global, j = loop_Global; i < HEIGHT; i++, j = loop_Global) {
			division = matrix[i][j];
			if ((matrix[i][j] == 0) || (matrix[i][j] == 1)) continue;
			for (; j < WIDTH; j++) {
				matrix[i][j] = matrix[i][j] / division;
			}
		}
		i = loop_Global, j = loop_Global;
		if (matrix[i][j] != 0) {
			for (; i < HEIGHT; i++, j = loop_Global) {
				if (matrix[i + 1][j] == 0) continue;
				for (; j < WIDTH; j++) matrix[i + 1][j] = matrix[i + 1][j] - matrix[loop_Global][j];
			}
		}
	}
	return matrix;
}


void Matrix::Display() {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) std::cout << (matrix[i][j]) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

