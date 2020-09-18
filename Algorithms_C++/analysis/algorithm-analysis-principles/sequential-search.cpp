// g++ sequential-search.cpp -o ss.exe
#include <iostream>

int search(uint16_t arr[], uint16_t l,uint16_t r, uint16_t v)
{
	for (uint16_t i = l; i < r; i++) {
		if (v == arr[i]) return i;
	}
	return -1;
}

int main(void) 
{
	uint16_t arr[10] = {1, 6, 3, 33, 21, 20, 2, 7, 44, 50}; // l = 0; r = 10;

	std::cout << search(arr, 0, 10, 50) << std::endl;

	return 0;
}