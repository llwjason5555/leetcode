#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if ((s1.size() + s2.size()) != s3.size())
			return false;
		bool flag = false;
		solve(s1, s2, s3,flag);
		return flag;
	}

	void solve(string s1, string s2, string s3,bool &flag)
	{
		if (s3.size() == 0 && s1.size() == 0 && s2.size() == 0)
		{
			flag=true;
			return;
		}

		if (s1.size() == 0)
		{
			if (s2 == s3)
			{
				flag = true;
				return;
			}
			else
			{
				
				return;
			}
		}

		if (s2.size() == 0)
		{
			if (s1 == s3)
			{
				flag = true;
				return;
			}
			else
			{
				
				return;
			}
		}

		if (s1[0] == s3[0])
			solve(s1.substr(1), s2, s3.substr(1),flag);
		if (s2[0] == s3[0])
			solve(s1, s2.substr(1), s3.substr(1),flag);
		
	}
};

int main()
{
	Solution so;
	cout << so.isInterleave(string("aabcc"), string("dbbca"), string("aadbbbaccc")) << endl;
	return 0;
}