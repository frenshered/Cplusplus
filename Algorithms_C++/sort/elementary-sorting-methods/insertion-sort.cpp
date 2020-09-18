// g++ insertion-sort.cpp -o is.exe

#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T> void exch(T& A, T& B)
{
	T t = A;	A = B;    B = t;
}


template <class T> void compexch(T& A, T& B)
{
	if (A > B) exch(A, B);
}

template <class T> void sort(T a[], int l, int r)
{
	for (int i = l + 1; i <= r; i++) 
	{
		for (int j = i; j > l; j--) 
		{
			compexch(a[j - 1], a[j]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a = new int[N];

	std::cout << "Filling..." << std::endl;

	if (sw) 
	{
		for (i = 0; i < N; i++)
		{
			a[i] = 100 * (1.0 * rand() / RAND_MAX);
		}
	}
	else
	{
		N = 0;

		while (std::cin >> a[N]) N++;
	}

	time_t start = time(NULL);

	std::cout << "Sorting..." << std::endl;

	sort(a, 0, N - 1);

	time_t end = time(NULL);

	// for (i = 0; i < N; i++)
	// {
	// 	std::cout << a[i] << " ";
	// }
	// std::cout << std::endl;

	delete a;

	std::cout << "Sorting time: " << end - start << "s" << std::endl;

	return 0;
}