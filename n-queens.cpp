#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> res;
		solve(n, res, 0);
		return res;
	}

	void solve(int n, vector<vector<string>> &res,int row)
	{
		if (row==n)
		{
			res.push_back(v);
			return;
		}

		if (row == 0)
		{
			for (int i = 0; i < n; i++)
			{
				string temp(n, '.');
				v.push_back(temp);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (isCol(i))
			{
				v[row][i] = 'Q';
			}
			else
				continue;
			if (row == 0)
			{
				solve(n, res, row + 1);
				v[row][i] = '.';
			}

			if (i>0&&i<n-1&&row>0)
			{
				if (v[row - 1][i - 1] == 'Q' || v[row - 1][i + 1] == 'Q')
				{
					v[row][i] = '.';
					continue;
				}
				else
				{
					solve(n, res, row + 1);
					v[row][i] = '.';
				}
			}

			if (i==n-1&&row>0)
			{
				if (v[row - 1][i - 1] == 'Q' )
				{
					v[row][i] = '.';
					continue;
				}
				else
				{
					solve(n, res, row + 1);
					v[row][i] = '.';
				}
			}

			if (i==0&&row>0)
			{
				if ( v[row - 1][i + 1] == 'Q')
				{
					v[row][i] = '.';
					continue;
				}
				else
				{
					solve(n, res, row + 1);
					v[row][i] = '.';
				}
			}

		}
		return;
	}

	bool isCol(int j)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i][j] == 'Q')
				return false;
		}
		return true;
	}

	vector<string> v;
};

int main()
{
	Solution so;
	vector<vector<string>> res;
	res = so.solveNQueens(4);
	cout << res.size() << endl;
	return 0;
}