#pragma once
//#include <vector>

template<typename T>
class Matrix
{
public:
	Matrix()
	{
		data = new T[4]; //Allocating 4 memory addresses with the byte size of T
		for (int i = 0; i < 4; i++) //Initializing them to 0
		{
			data[i] = 0;
		}
	}

	Matrix(T r0c0, T r0c1, T r1c0, T r1c1) //2x2 Matrix constructor
	{
		data = new T[4];
		data[0] = r0c0;
		data[1] = r0c1;
		data[2] = r1c0;
		data[3] = r1c1;		
	}


	Matrix(const Matrix &source) //Deep copy constructor
	{
		data = new T[4];
		data[0] = source.data[0];
		data[1] = source.data[1];
		data[2] = source.data[2];
		data[3] = source.data[3];

	}

	~Matrix()
	{
		delete[] data;
	}

	Matrix& operator=(const Matrix &source) //Assignment operator overloading
	{
		if (&source == this) //If the objects are the same, we do nothing
		{
			return *this;
		}

		delete[] data; //Deleting the old data
		data = new T[4]; //Allocating the new memory and assigning the values from the source
		data[0] = source.data[0];
		data[1] = source.data[1];
		data[2] = source.data[2];
		data[3] = source.data[3];
		return *this;
	}

	//Printing the array in a 2x2 matrix form
	void printData()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				std::cout << data[i * 2 + j] << " ";
			}
			std::cout << std::endl;
		}
	}

	//Setting the value using row and col on a 1d array
	void setValue(int row, int col, T value)
	{
		data[row * 2 + col] = value;
	}

	//Getting the value using row and col on a 1d array
	void getValue(int row, int col)
	{
		std::cout << data[row * 2 + col] << std::endl;
	}

	void calculateDeterminant()
	{	
		std::cout<< ((data[0]) * (data[3])) - ((data[2])*(data[1]))<<std::endl;
	}

	Matrix<T> operator+(const Matrix &source) //Operator+ overloading
	{
		Matrix temp = Matrix();
		temp.data[0] = this->data[0] + source.data[0];
		temp.data[1] = this->data[1] + source.data[1];
		temp.data[2] = this->data[2] + source.data[2];
		temp.data[3] = this->data[3] + source.data[3];
		return temp;
	}

private:
	T * data = nullptr;
};