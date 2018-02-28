#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int max = 0;
//		string res=" ";
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = s.size()-1; j >=i; j--)
//			{
//				if (isQualified(s.substr(i, j - i + 1)))
//				{
//					if (j - i + 1>max)
//					{
//						max = j - i + 1;
//						res = s.substr(i, j - i + 1);
//						break;
//					}
//				}
//
//			}
//			if (s.size() - i < max)
//				break;
//		}
//		return res;
//	}
//
//	bool isQualified(string s)
//	{
//		if (s.size() == 1)
//			return true;
//		for (int i = 0; i < s.size() / 2; i++)
//			if (s[i] != s[s.size() - 1 - i])
//				return false;
//		return true;
//	}
//
//};

class Solution {
public:
	string longestPalindrome(string s) {
		int max = 0;
		string res = " ";
		const int len = s.size();
		bool dp[1001][1001];
		//dp[0][0] = true;
		//fill_n(&dp[0][0], 1001 * 1001, false);
		for (int i = 1; i < s.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (s[i] == s[j] && ((i-j) < 3 || dp[i - 1][j + 1]))
				{
					dp[i][j] = true;
					if (max < i - j+1)
					{
						max = i - j + 1;
						res = s.substr(j, i - j + 1);
					}
				}
			}
		}
		return res;
	}

	

};

int main()
{
	Solution so;
	string s("abcsffscag");
	//string s("acabba");

	string res;
	res= so.longestPalindrome(s);
	cout << res << endl;
	//cout << so.isQualified("abccba") << endl;
	return 0;
}