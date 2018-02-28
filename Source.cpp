#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct
};

int main()
{
	int n, L;
	cin >> n >> L;
	int parent[1000];
	for (int i = 0; i < n - 1; i++)
		cin >> parent[i];
	for (int i = 0; i < n - 1; i++)
		cout << parent[i] << endl;
	return 0;
}