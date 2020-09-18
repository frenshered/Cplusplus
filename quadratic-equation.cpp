#include <iostream>  // g++ test.cpp -o t
#include <string>
#include <math.h>

using namespace std;

bool twoRadical = false;
int Value_A = 1;
int Value_B = 1;
int Value_C = 1;

void CoutTwoRadical(float x_1, float x_2)
{
    cout << "Radical:" << "\t" << x_1 << "  " << x_2 << endl;
}

int Discriminant(int a, int b, int c)
{
    int Discr = ( b * b ) - ( 4 * a * c );

    if (Discr == 0) 
    {
        return 0;
    } 
    if (Discr < 0)
    {
        return -1;
    }
    if (Discr > 0) 
    {
        return Discr;
    }
}

float Radical(int a, int b)
{
    if (Discriminant(Value_A, Value_B, Value_C) == 0) // 1
    {
        float X = -b / 2 * a;
        return X;
    }
    if (Discriminant(Value_A, Value_B, Value_C) < 0)  // 0
    {
        return 0;
    }
    if (Discriminant(Value_A, Value_B, Value_C) > 0) // 2
    {
        twoRadical = true;
        float X_1 = ( -b + sqrt( Discriminant(Value_A, Value_B, Value_C) ) ) / 2 * a;
        float X_2 = ( -b - sqrt( Discriminant(Value_A, Value_B, Value_C) ) ) / 2 * a;

        float arrX[2];

        arrX[0] = X_1;
        arrX[1] = X_2;

        float *px = arrX;
        
        CoutTwoRadical(arrX[0], arrX[1]);

        return *px;
    }   
}

void CoutRadical(float x_1, float x_2)
{
    if ( Radical(Value_A, Value_B) != 0 ) 
    {
        cout << "Radical:" << "\t" << Radical(Value_A, Value_B) << endl;
    } 
        else if ( Radical(Value_A, Value_B) == 0 )
    {
        cout << "Radical:" << "\t" << "NONE" << endl;
    } 
        else if ( Radical(Value_A, Value_B) != 0 && twoRadical == true)
    {
        float arrX = Radical(Value_A, Value_B);

        cout << "Radical:" << "\t" << arrX;
    }
}

int main() 
{
    string start = "not";

    cout << "Hello haker )" << "\n" << "This is program to solve quadratic education" << "\n" << "Education looks like: ax^2 + bx + c = 0" << endl;
    cout << "To start enter   OK" << endl;
    cin >> start;

    if (start == "ok")
    {
        cout << "Starting..." << endl;
        cout << "Enter a value for ( a ), ( b ), ( c )" << endl;
        cin >> Value_A >> Value_B >> Value_C; 

        Radical(Value_A, Value_B);

        if (twoRadical == false) {
            CoutRadical(1.0, 1.0);
        }

        string contin;

        cout << "Do you want to continue ? Enter yes/no" << endl;
        cin >> contin;

        if (contin == "yes") 
        {
            main();
        }
            else
        {
            cout << "See you friends" << endl; 
        }

    } 
        else
    {
       cout << "See you friends" << endl;    
    }

    return 0;
}