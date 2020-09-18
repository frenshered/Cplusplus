#include <iostream> // g++ test_3.cpp -o t3.exe
#include <string>

using namespace std;

struct My {
	int age;
	string name;
	string* hobi;
};

void initMy(My& user, int age, string name) 
{
	user.name = name;
	user.age = age;
	user.hobi = new string[2];
}

void readMy() 
{
	My user;
	string name = "serhiy";
	int age = 17;

	initMy(user, age, name);

	for (int i = 0; i < 2; i++)
	{
		cin >> user.hobi[i];
	}

	for (int i = 0; i < 2; i++)
	{
		cout << user.hobi[i] << "\t";
	}
}

int main()
{
	readMy();

	return 0;
}