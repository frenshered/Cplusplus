//  g++ search-string.cpp -o ss.exe
#include <iostream>
#include <string>

const int N = 10000;

int main(int argc, char *argv[])
{
 	using std::cin;

	int i;
	char t;
	char a[N], *p = argv[1];

	for (i = 0; i < N - 1; i++, a[i] = t)
	{
		cin.get(t);
		if (t == '0') break;
	}
		

	a[i] = 0;

	for (i = 0; a[i] != 0; i++) 
	{
		int j;

		for (j = 0; p[j] != 0; j++) 
			if (a[i + j] != p[j]) break;

		if (p[j] == 0) std::cout << i << " ";
	}

	std::cout << std::endl;

	return 0;
}