#include <iostream>
#include <ctime>

void bubleSort(int arr[], int size)
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

void outputArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void createArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

int main()
{
    int size;
    int* arr = new int[size];

    std::cout << "Enter array size: " << std::endl;
    std::cin >> size;

    std::cout << "not sorted: \n";
    createArr(arr, size);

    outputArr(arr, size);

    bubleSort(arr, size);

    std::cout << "sorted: \n";
    outputArr(arr, size);

    return 0;
}
