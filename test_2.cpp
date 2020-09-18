#include <iostream>  // g++ test_2.cpp -o test_2
#include <vector>

using namespace std;

int a = 10;

int *b = &a;

vector<int> integers = {1,2,3,4,5,6,7,8,9,0};

vector<int> *p = &integers;

void abc(vector<int> data)
{
    for (int x : data) {
        cout << x << "\t";
    }
}

struct Vector {
    int size;
    double *elem;
};

void user_init(Vector& user, int sz) 
{
    user.elem = new double[sz];
    user.size = sz;
    
    cout << user.elem << "\t" << user.size << endl;
}

double read(int x) 
{
    Vector user;
    user_init(user, x);

    for (int i = 0; i != x; i++) 
    {
        cin >> user.elem[i];
    }

    double sum = 0;

    for (int i = 0; i != x; i++) 
    {
        sum += user.elem[i];
    }
    
    return sum;
}

int main() 
{
    abc( *p );

    cout << "\n" << &a << "\t" << b << "\t" << *b << endl;

    int a = 10;

    double y = read(a);

    cout << "Sum: " << y << endl;

    return 0;
}