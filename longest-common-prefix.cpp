#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0)
			return string("");
		string res;
		int min = strs[0].size();
		if (min == 0)
			return string("");
		res = strs[0];
		int j = 0, k = 0;
		for (int i = 1; i < strs.size(); i++)
		{
			if (strs[i].size() == 0)
			{
				min = 0;
				break;
			}
			j = 0;
			k = 0;
			while (res[j] == strs[i][k] && j < res.size() && k < strs[i].size())
			{
				j++;
				k++;
			}
			if (j <min)
			{
				min = j;
				if (min != 0)
					res = res.substr(0, min);
			}
			if (min == 0)
				break;

		}

		if (min == 0)
			return string("");
		else
			return res;
	}
};

int main()
{
	Solution so;
	vector<string> strs = { "abce", "abcd", "abcdefy", "abcdg" };
	cout << so.longestCommonPrefix(strs) << endl;
	return 0;
}