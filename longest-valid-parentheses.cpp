#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int max = 0;
		if (s.size() <2)
			return max;
		bool dp[100][100];
		memset(&dp[0][0], 0, 10000);
		for (int i = 1; i < s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (s[j] == '('&&s[i] == ')'&&dp[i - 1][j + 1])
				{
					dp[i][j] = true;
					if (i - j + 1>max)
						max = i - j + 1;
					continue;
				}
				string ss = s.substr(j, i - j + 1);
				if (isValid(ss) && i - j + 1 > max)
					max = i - j + 1;

			}
		}
		return max;
	}

	bool isValid(string s)
	{
		int len = s.size();
		if (len % 2)
			return false;
		stack<char> st;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
				st.push(')');
			else if (st.empty())
				return false;
			else
				st.pop();
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	Solution so;
	string s("(())(()");
	//string s(")()())");
	cout << so.longestValidParentheses(s) << endl;
	return 0;
}