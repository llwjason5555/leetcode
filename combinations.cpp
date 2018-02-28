#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {

		vector<vector<int>> res;
		if (k>n)
			return res;
		solve(res, n, k, 1);
		return res;
	}

	void solve(vector<vector<int>> &res, int n, int k, int beg)
	{
		if (k == 0)
		{
			res.push_back(v);
			return;
		}

		for (int i = beg; i <= n; i++)
		{
			v.push_back(i);
			solve(res, n, k - 1, i + 1);
			v.pop_back();
		}
	}

	vector<int> v;
};

int main()
{
	Solution so;
	vector<vector<int>> res;
	res = so.combine(4, 2);
	cout << res.size() << endl;
	return 0;
}