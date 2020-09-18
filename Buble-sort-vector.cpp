#include <iostream> //  g++ Buble-sort-vector.cpp -o Buble-sort-vector
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int count = 0;

int numberOfPermutation = 0;

vector<int> arr;

int Random()
{
    return rand() % 100;
}

void CoutSortedVector(float time)
{
    cout << "Sorted vector: " << endl;

    for (int i = 1; i <= arr.size(); i++)
    {
        cout << arr[i - 1] << "\t";

        if (i % 10 == 0) 
        {
            cout << endl;
        }
    }

    int ms_time = time * 1000;

    cout << "Number of permutation: " << numberOfPermutation << endl;
    cout << "Sorted time: " << ms_time << "ms" << endl;
}

void SortVector() 
{
    cout << "Sorting vector..." << endl;

    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = 1; j < arr.size(); j++)
        { 
            if ( arr[i] < arr[j] ) 
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                numberOfPermutation++;
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<float> sort_time = end_time - start_time;

    CoutSortedVector( sort_time.count() );
}

void CoutVector()
{
    cout << "Start vector: " << endl;

    for (int i = 1; i <= arr.size(); i++) 
    {
        cout << arr[i - 1] << "\t";
        if (i % 10 == 0) 
        {
            cout << endl;
        }
    }

    cout << endl;

    SortVector();
}

void Filling() 
{
    for (int i = 0; i < count; i++) 
    {
        arr.push_back( Random() );
    }

    CoutVector();
}

int main()
{
    cout << "Enter vector size: ";
    cin >> count;
    cout << endl;

    Filling();

    return 0;
}