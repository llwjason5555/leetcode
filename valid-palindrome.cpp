#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;
		int beg = 0, end = s.size() - 1;
		while (beg<end)
		{
			if (isalpha(s[beg]) && isalpha(s[end]))
			{
				if (s[end] == s[beg])
				{
					beg++;
					end--;

				}
				else
					return false;
			}
			if (!isalpha(s[beg]))
			{
				beg++;

			}
			if (!isalpha(s[end]))
			{
				end--;

			}
		}

		return true;
	}
};


int main()
{
	Solution so;
	cout << so.isPalindrome("abba") << endl;
	return 0;
}