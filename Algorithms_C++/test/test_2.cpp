// g++ test_2.cpp -o t2.exe
#include <iostream>
#include <cstdlib>

const int R = 20;
const int C = 10;

void filling(int (*arr)[C], int row, int col)
{
	int num;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			num = rand() % 100;
			arr[i][j] = num;
		}
	}
}

void output(int (*arr)[C], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void bubleSort(int (*arr)[C], int row, int col)
{
	int tmp = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				if (arr[i][j] < arr[i][k])
				{
					tmp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = tmp;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int array[R][C];
	
	filling(array, R, C);
	output(array, R, C);
	bubleSort(array, R, C);
	output(array, R, C);

	return 0;
}