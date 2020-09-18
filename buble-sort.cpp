#include <iostream> //     g++ test.cpp -o test.exe

using namespace std;

int arrLength;

unsigned int count = 0;

int arr[] = {};

void sFun() 
{
    for (int i = 0; i < arrLength; i++) 
    {
        for (int j = i + 1; j < arrLength; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }

    cout << "Sorting array..." << endl;

    for (int i = 1; i <= arrLength; i++) 
    {
        cout << arr[i - 1] << "\t";

        if (i % 10 == 0) {
            cout << "\n";
        }
    }

    cout << "\nCount: " << count << "\t" << sizeof(count);
}

void start()
{
    cout << "Starting..." << endl;

    cout << "Start array: " << endl;

    for (long int i = 1; i <= arrLength; i++) 
    {
        cout << arr[i - 1] << "\t";
        
        if (i % 10 == 0) 
        {
            cout << "\n";
        }
    } 

    cout << endl;

   sFun();
}

int main()
{
    cout << "Enter lenght:" << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++) 
    {
        arr[i] = rand() % 100;
    }

    start();

    return 0;
}
