#include<iostream>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		set<string> res;
		solve(res, s);
		return res.size();
	}

	void solve(set<string> &res, string s)
	{
		if (s.size() == 0)
		{
			cout << str << endl;
			res.insert(str);
			//str.clear();
			return;
		}

		for (int i = 0; i<1; i++)
		{
			if (s[i] == '0'&&i != s.size() - 1)
			{
				s = s.substr(i + 1);
				continue;
			}
			if (s[i] == '0'&&i == s.size() - 1)
			{
				solve(res, string(""));
			}
			str.push_back(s[i] - '0' - 1 + 'A');
			solve(res, s.substr(i + 1));
			str.pop_back();
			if (i + 1<s.size())
			{
				int val = (s[i]-'0') * 10 + (s[i + 1]-'0');
				if (val<27)
				{
					str.push_back(val - 1 + 'A');
					solve(res, s.substr(i + 2));
					str.pop_back();
				}
			}
		}
	}

	string str;
};

int main()
{
	string s("125632145678321");
	Solution so;
	cout << so.numDecodings(s) << endl;
	return 0;
}