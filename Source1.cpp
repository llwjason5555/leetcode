//#include<iostream>
//#include<vector>
//#include<map>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<long> v(n, 0);
//	for (int i = 0; i<n; i++)
//		cin >> v[i];
//	/*n = 5;
//	vector<long> v = { 1, 5, 6, 2, 1 };*/
//	//map<long,int> m;
//	//for(int i=0;i<n;i++)
//	//   m[v[i]]=i;
//	vector<long> v1(v.begin(), v.end());
//	sort(v1.begin(), v1.end());
//	int dist = abs(v[1] - v[0]);
//	int temp = 1;
//	for (int i = 2; i<n; i++)
//	{
//		if (abs(v[i] - v[i - 1]) > dist)
//		{
//			dist = abs(v[i] - v[i - 1]);
//			if (abs(v[i] - v[i - 2]) > abs(v[i - 1] - v[i - 2]))
//				temp = i;
//			else temp = i - 1;
//		}
//			
//	}
//
//	long val = v[temp];
//
//	//int beg=m[v1[temp]];
//	//for(int i=temp;i<n;i++)
//	//{
//	//    if(m[v1[i]]<m[v1[temp]])
//	//        beg=m[v1[i]];
//	//}
//
//	vector<long> Q;
//	vector<long> D;
//
//	for (int i = 0; i<n; i++)
//		if (v[i] >= val)
//			D.push_back(v[i]);
//		else
//			Q.push_back(v[i]);
//
//	long res = 0;
//	//if(Q.siz()==0||D.size()==0)
//	//{
//	//    cout<<res<<endl;
//	//    return 0;
//	//}
//
//	for (int i = 1; i<Q.size(); i++)
//		res = res +abs(Q[i]-Q[i-1]);
//	for (int i = 1; i<D.size(); i++)
//		res = res + abs(D[i] - D[i - 1]);
//	cout << res << endl;
//	return 0;
//
//
//}
//
//int main()
//{
//	int n;
//	//cin >> n;
//	n = 23;
//	vector<long> v = { 24, 13, 2, 4, 54, 23, 12, 53, 12, 23, 42, 13, 53, 12, 24, 12, 11, 24, 42, 52, 12, 32, 42 };
//	/*vector<long> v(n,0);
//	for (int i = 0; i < n; i++)
//		cin>>v[i];*/
//	vector<vector<long>> dp(n, vector<long>(n, 0));
//	vector<long> v1;
//	vector<long> v2;
//	int x = 0, y = 0;
//
//	for (int i = 1; i < n; i++)
//	{
//		int k = 0;
//		while (k < i)
//		{
//			v1.push_back(v[k]);
//			k++;
//		}
//		if (v1.size() == 1)
//			dp[i][1] = 0;
//		for (int m = 0; m < v1.size()-1; m++)
//		{
//			if (v1.size() != 0)
//				dp[i][m + 1] =abs(v1[m + 1] - v1[m])+dp[i][m];
//			//if (i>1 && dp[i][m + 1]>dp[i - 1][n-1])
//		}
//		for (int j = i; j < n; j++)
//		{
//			if (j == i)
//			{
//				v2.push_back(v[i]);
//				dp[i][j] = dp[i][j - 1];
//				continue;
//			}
//
//			x = v1[v1.size() - 1];
//			y = v2[v2.size() - 1];
//			if (abs(x - v[j]) > abs(y - v[j]))
//			{
//				v2.push_back(v[j]);
//				dp[i][j] = dp[i][j-1] + abs(y - v[j]);
//			}
//			else
//			{
//				v1.push_back(v[j]);
//				dp[i][j] = dp[i][j-1] + abs(x - v[j]);
//			}
//
//		}
//		v1.clear();
//		v2.clear();
//
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << dp[i][j] << ' ';
//		cout << endl;
//	}
//	int min = dp[n-1][n-1];
//	for (int i = 1; i < n; i++)
//	{
//		cout << dp[i][n - 1] << endl;
//		if (dp[i][n - 1] < min)
//			min = dp[i][n - 1];
//	}
//	cout << min << endl;
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

typedef long long llong;

inline void getMin(llong& n, llong x) {
	n > x && (n = x);
}

#define MAXN 2020

int n;
int v[MAXN], cost[MAXN];

void read() {
	scanf_s("%d%d", &n, v);
	for (int i = 1; i < n; ++i) {
		scanf_s("%d", v + i);
		cost[i] = abs(v[i] - v[i - 1]);
	}
}

llong dp[MAXN][MAXN];

void work() {
	llong res = (1ll << 63) - 1;
	for (int i = 2; i < n; ++i) {
		//    dp[i][0] = dp[i - 1][0] + cost[i];
		dp[i][i - 1] = dp[i - 1][i - 2] + cost[i - 1];
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			dp[i][j] = dp[i - 1][j] + cost[i];
			getMin(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		getMin(res, dp[n - 1][i]);
	}
	printf("%lld\n", res);
}

int main() {
	read();
	work();
	return 0;
}

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >>n ;
	vector<long> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<vector<long>> dp(n, vector<long>(n, 0));

	for (int i = 2; i < n; i++)
	{
		//dp[i][0] = dp[i - 1][0] + abs(v[i] - v[i - 1]);
		dp[i][i - 1] = dp[i - 1][i - 2] + abs(v[i-1] - v[i - 2]);
	}

	for (int i = 2; i < n; i++)
	{
		long min = dp[i][i - 1];
		for (int j = 0; j < i - 1; j++)
		{
			dp[i][j] = dp[i - 1][j] + abs(v[i] - v[i - 1]);
			if (dp[i - 1][j] + abs(v[i] - v[j]) < min)
				min = dp[i - 1][j] + abs(v[i] - v[j]);
		}
		dp[i][i - 1] = min;
	}

	long res =1000000;
	for (int i = 0; i < n-1; i++)
		if (dp[n - 1][i] < res)
			res = dp[n - 1][i];
	cout<<res<<endl;
	return 0;

}