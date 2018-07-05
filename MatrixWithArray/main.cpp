#include <iostream>
#include "Matrix.h"

template<typename T>
void printMatrix(Matrix<T> m)
{
	m.printData();
}

int main()
{
	Matrix<double> mat(1, 4, 5, 6);
	Matrix<double> mat2(2, 3, 6, 7);
	Matrix<double> mat3;

	std::cout << "mat:" << std::endl;
	mat.printData();
	std::cout << "mat2:" << std::endl;
	mat2.printData();
	std::cout << "mat3:" << std::endl;
	mat3.printData();

	std::cout << "mat Determinant: ";
	mat.calculateDeterminant();
	std::cout << "mat2 Determinant: ";
	mat2.calculateDeterminant();
	std::cout << "mat3 = mat + mat2"<<std::endl;
	mat3 = mat + mat2;

	std::cout << "mat3:" << std::endl;
	printMatrix(mat3);

	std::cout << "mat3 Determinant: " ;
	mat3.calculateDeterminant();

	std::cout << "mat[0][1] = 23" << std::endl;
	mat.setValue(0, 1, 23);
	std::cout << "mat:" << std::endl;
	mat.printData();

	std::cout << "mat2[1][0]= ";
	mat2.getValue(1, 0);

	std::cin.get();
	return 0;
}