#define HEIGHT 4
#define WIDTH 5
typedef float element;
typedef element (*mat_element)[WIDTH];


class Matrix {
public :
	element (*matrix)[WIDTH];
	Matrix(element(*matrix_Args)[WIDTH]);
	mat_element Gaussian_Method();
	void	Display();

	~Matrix() {}
};
