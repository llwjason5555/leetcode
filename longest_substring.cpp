#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;
		for (int i = 0; i < s.size(); i++)
			for (int j = i; j < s.size(); j++)
			{
				if (isQualified(s.substr(i, j - i + 1)))
				{
					if (j - i + 1>max)
						max = j - i + 1;
				}
				else
					break;
			}
		return max;
	}

	bool isQualified(string s)
	{
		if (s.size() == 1)
			return true;
		sort(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == s[i + 1])
				return false;

		}
		return true;
	}
};

int main()
{
	Solution so;
	string s("bbbb");
	int ret=so.lengthOfLongestSubstring(s);
	cout << s.substr(2, 3) << endl;
	cout << ret << endl;
	return 0;
}