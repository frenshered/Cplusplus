// g++ graph-representation-as-adjacency-lists.cpp -o gral.exe
#include <iostream>

const int V = 10;

struct  Node
{
	int v;
	Node* next;

	Node(int x, Node* t)
	{
		v = x;
		next = t;
	}
};

typedef Node *link;

int main()
{
	int i, j;
	link adj[V];

	for (i = 0; i < V; i++) adj[i] = 0;

	while (std::cin >> i >> j)
	{
		adj[j] = new Node(i, adj[j]);
		adj[i] = new Node(j, adj[i]);
	}
}

