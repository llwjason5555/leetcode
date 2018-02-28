#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vx(n, 0);
	vector<int> vy(n, 0);
	//int x,y;
	for (int i = 0; i<n; i++)
	{
		cin >> vx[i] >> vy[i];
	}

	int maxX = vx[0], minX = vx[0], maxY = vy[0], minY = vy[0];
	for (int i = 1; i<n; i++)
	{
		if (vx[i]>maxX)
			maxX = vx[i];
		if (vx[i]<minX)
			minX = vx[i];
		if (vy[i]>maxY)
			maxY = vy[i];
		if (vy[i]<minY)
			minY = vy[i];
	}

	if (maxX - minX>maxY - minY)
		cout << (maxX - minX)*(maxX - minX) << endl;
	else
		cout << (maxY - minY)*(maxY - minY) << endl;
	return 0;
}

