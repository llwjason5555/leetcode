#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		for (int i = 0; i < n; i++)
			dict.push_back(i + 1);
		solve(res, n, k);
		return res;
	}

	void solve(string &res, int n, int k)
	{
		if (k == 0)
		{
			for (int i = dict.size() - 1; i >= 0; i--)
			{
				res.push_back(dict[i] +'0');

			}
			return;
		}

		int num = 1;
		for (int i = 1; i < n; i++)
			num = num * i;
		int m = k / num;//ษฬ
		k = k%num;//ำเสý
		if (k)
		{
			res.push_back(dict[m] + '0');
			auto it = dict.begin() + m;
			dict.erase(it);
		}
		else
		{
			res.push_back(dict[m-1] + '0');
			auto it = dict.begin() + m-1;
			dict.erase(it);
		}
		
		solve(res, n - 1, k);
	}

	vector<int>  dict;
};

int main()
{
	Solution so;
	cout << so.getPermutation(4, 6) << endl;
	return 0;
}