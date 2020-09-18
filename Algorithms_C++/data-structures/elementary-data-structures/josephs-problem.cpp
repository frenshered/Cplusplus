// g++ josephs-problem.cpp -o jp.exe
#include <iostream>
#include <cstdlib>

struct Node
{
	int item;
	Node* next;

	Node(int x, Node* t) 
	{
		item = x;
		next = t;
	}
};

typedef Node* link;

int main(int argc, char const *argv[])
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);

	link t = new Node(1, 0);
	t -> next = t;
	link x = t;

	for (i = 2; i <= N; i++) x = (x -> next = new Node(i, t));

	while (x != x -> next)
	{
		for (i = 1; i < M; i++) x = x -> next;

		x -> next = x -> next -> next;
	}

	std::cout << x -> item << std::endl;

	return 0;
}