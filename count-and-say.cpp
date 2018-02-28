#include<iostream>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)
			return string("");
		string s = "1";
		n--;
		while (n)
		{
			n--;
			if (s.size() == 1)
			{
				s = "11";
				continue;
			}
			string ss;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '1')
				{
					if (i == s.size() - 1)
					{
						ss = ss + "11";
						continue;
					}
					if (s[i + 1] == '1')
					{
						ss = ss + "21";
						i++;
					}
					else
						ss = ss + "11";

				}
				else
					ss = ss + "12";
			}
			s = ss;

		}
		return s;
	}
};

int main()
{
	Solution so;
	cout << so.countAndSay(5) << endl;
	return 0;
}