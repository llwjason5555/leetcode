#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool wordBreakHelp(string s, vector<string> &dict, vector<string> unmatch)
{
	int length = s.size();
	int i;
	bool flag = false;
	for (i = 1; i < length; i++)
	{
		string sub = s.substr(0, i);
		auto it = find(dict.begin(),dict.end(),sub);
		if (it != dict.end())
		{
			string sub_last = s.substr(i);
			auto iit = find(unmatch.begin(), unmatch.end(), sub_last);
			if (iit != unmatch.end()) continue;
			else
			{
				flag = wordBreakHelp(sub_last, dict, unmatch);
				if (flag)return true;
				else unmatch.push_back(sub_last);
			}
		}

	}
	return false;
}


bool wordBreak(string s, vector<string> &dict)
{

}

int main()
{
	
}