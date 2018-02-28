#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		map<string, int> dict;
		vector<int> res;
		if (!S.size() || !L.size())
			return res;
		for (int i = 0; i < L.size(); i++)
			dict[L[i]] ++;

		int m = L.size();
		int n = L[0].size();
		int size = m*n;
		for (int i = 0; i < S.size() - size + 1; i++)
		{
			for (int a = 0; a < m; a++)
			{
				dict[L[a]] = 0;
			}
			for (int a = 0; a < m; a++)
			{
				dict[L[a]] ++;
			}
			string s = S.substr(i, size);
			int j = 0;
			while (j < m)
			{

				string ss = s.substr(j*n, n);
				if (dict.find(ss) != dict.end())
					dict[ss]--;
				else
					break;
				j++;
			}

			if (j != m)
				continue;
			int k = 0;
			for (; k < m; k++)
			{
				if (dict[L[k]])
					break;
			}

			if (k == m)
				res.push_back(i);
		}

		return res;
	}
};

int main()
{
	string S("foobarasdbarfoofgh");
	vector<string> L = { "foo", "bar" };
	Solution so;
	vector<int> v;
	v = so.findSubstring(S, L);
	cout << v.size() << endl;
	return 0;
}