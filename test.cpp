#include <iostream>   // g++ test.cpp -o t
#include <string>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 62;

bool PassOk = false;
bool BadPass = false;

// vector<char> PASSWORD_ARRAY = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "A", "b", "B", "c", "C", "d", "D", "e", "E", "f", 
//                                     "F", "G", "g", "h", "H", "i", "I", "j", "J", "k", "K", "l", "L", "m", "M", "n", "N", "o", "O", "p", 
//                                     "P", "q", "Q", "r", "R", "s", "S", "t", "T", "u", "U", "v", "V", "w", "W", "x", "X", "y", "Y", "z", "Z"
//                                 };

string PASSWORD_ARRAY[ARRAY_SIZE] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "A", "b", "B", "c", "C", "d", "D", "e", "E", "f", 
                                    "F", "G", "g", "h", "H", "i", "I", "j", "J", "k", "K", "l", "L", "m", "M", "n", "N", "o", "O", "p", 
                                    "P", "q", "Q", "r", "R", "s", "S", "t", "T", "u", "U", "v", "V", "w", "W", "x", "X", "y", "Y", "z", "Z"
                                    };

string PASSWORD = "aaa";

void CheckInputPass()
{
    for (int i = 0; i < PASSWORD.length(); i++) 
    {
        string pass_i = wcsstr(PASSWORD[i]);
        for (int j = 0; j < ARRAY_SIZE; j++) 
        {
            string pass_j = PASSWORD_ARRAY[j];

            // if (pass_i == pass_j)
            // {
            //     cout << "OK" << endl;
            // }
        }
    }

    if (BadPass == false)
    {
        cout << "Password OK" << endl;
    }

}

int main()
{
    //cout << "Enter password:" << endl;
    //cin >> PASSWORD;

    for (int i = 1; i <= ARRAY_SIZE; i++) 
    {
        cout << PASSWORD_ARRAY[i-1] << "\t";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    cout << endl;

    CheckInputPass();

    return 0;
}