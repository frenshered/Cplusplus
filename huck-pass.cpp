#include <iostream>  // g++ huck-pass.cpp -o huck-pass
#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

const int MAX_PASS_VALUE = 100000000; // 9999

string RandPass()
{
    srand(time(NULL));

    int r = rand() % 1000 * 100000; 

    stringstream ss;
    ss << r;
    string str;
    ss >> str;

    return str;
}

string ConvertIntToString(int a) // int --> string
{
    stringstream ss;
    ss << a;
    string str;
    ss >> str;

    return str;
}

string password = RandPass();

int ConvertStringToInt() // string --> int
{
    int tmp = atoi(password.c_str());

    return tmp;
}

void Hack() 
{
    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < MAX_PASS_VALUE; i++) 
    {
        string string_i;

        if (ConvertIntToString(i).length() == 1) 
        {
            string_i = "0000000" + ConvertIntToString(i);
        }

        if (ConvertIntToString(i).length() == 2) 
        {
            string_i = "000000" + ConvertIntToString(i);
        }

        if (ConvertIntToString(i).length() == 3) 
        {
            string_i = "00000" + ConvertIntToString(i);
        }

        if (ConvertIntToString(i).length() == 4) 
        {
            string_i = "0000" + ConvertIntToString(i);
        }
        if (ConvertIntToString(i).length() == 5) 
        {
            string_i = "000" + ConvertIntToString(i);
        }
        if (ConvertIntToString(i).length() == 6) 
        {
            string_i = "00" + ConvertIntToString(i);
        }
        if (ConvertIntToString(i).length() == 7) 
        {
            string_i = "0" + ConvertIntToString(i);
        }
        if (ConvertIntToString(i).length() == 8) 
        {
            string_i = ConvertIntToString(i);
        }

        cout << string_i << endl;

        if (string_i == password)
        {
            cout << "Password: " << string_i << endl;
            break;
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<float> sort_time = end_time - start_time;

    int ms_time;

    if ( (sort_time.count() * 1000) > 9999) 
    {
        cout << "Huck time: " << sort_time.count() << "s" << endl;
    }   
        else
    {
        ms_time = sort_time.count() * 1000;
        cout << "Huck time: " << ms_time << "ms" << endl;
    }
}

int main()
{
    Hack();

    return 0;
}