// g++ binary-search.cpp -o bs.exe
#include <iostream> // this algorithm is for ordered data only !!!

int search(uint16_t arr[], uint16_t l, uint16_t r, uint16_t v)
{
	while (r >= l) {
		uint16_t m = (r + l) / 2;

		if (v == arr[m]) return m;

		if (v < arr[m]) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return -1;
}

int main(void)
{
	uint16_t arr[10] = {1, 6, 8, 10, 21, 22, 29, 70, 74, 90};

	std::cout << search(arr, 0, 10, 74) << std::endl; // v >= arr[0] && v <= arr[max] !!!!

	return 0;
}
