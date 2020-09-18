// g++ calculating-the-nearest-point.cpp -o cnp.exe
#include <iostream>
#include <cmath>
#include <cstdlib>

struct Point
{
	float x;
	float y;
};

float distance(Point a, Point b) 
{
	float dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

float randFloat() 
{
	return 1.0 * rand() / RAND_MAX;
}

int main(int argc, char const *argv[])
{
	  
	float d = atof(argv[2]);
	int i, j, cnt, N = atoi(argv[1]);
	Point *a = new Point[N];

	for (i = 0; i < N; i++) {
		a[i].x = randFloat(); 
		a[i].y = randFloat();
	}

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (distance(a[i], a[j]) < d) cnt++;
		}
	}

	std::cout << cnt << " pairs within " << d << std::endl;

	return 0;
}