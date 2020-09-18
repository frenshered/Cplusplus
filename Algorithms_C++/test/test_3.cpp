// g++ test_3.cpp -o t3.exe
#include <iostream>
#include <cstdlib>
#include <string>

int SIZE;

void sorting(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j]) 
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void filling(int* arr, int size) 
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void output(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
		if ((i + 1) % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void search(int* arr, int left, int right, int mid, int target) 
{
	if (arr[mid] == target) 
	{
		std::cout << "Index: " << mid << "\t" << "Target: " << arr[mid] << std::endl;
	}
	else 
	{
		if (arr[mid] < target)
		{
			left = mid;
			mid = (left + right) / 2;
			search(arr, left, right, mid, target);
		}
		else
		{
			right = mid;
			mid = (left + right) / 2;
			search(arr, left, right, mid, target);
		}
		// std::cout << "NULL" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "Enter size of array: ";
	std::cin >> SIZE;
	std::cout << std::endl;

	int* arr = new int[SIZE];

	int target;

	filling(arr, SIZE);

	std::cout << "Start sorting..." << std::endl;
	sorting(arr, SIZE);

	// output(arr, SIZE);

	std::cout << "Enter target: ";
	std::cin >> target;
	std::cout << std::endl;

	std::cout << "Start searching..." << std::endl;
 	search(arr, 0, SIZE - 1, SIZE / 2, target);

 	delete arr;

	return 0;
}