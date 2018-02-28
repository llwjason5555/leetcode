#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>

using namespace std;

bool isValid(string s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
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

int main()
{
	string s;
	cin >> s;
	if (s.size() % 2 == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	if (s.size() == 2)
	{
		cout << "0" << endl;
		return 0;
	}

	if (s.size() == 4)
	{
		cout << "1" << endl;
		return 0;
	}

	int len = s.size();
	string str="";
	for (int i = 0; i < len/2; i++)
		str = str + "()";
	sort(str.begin(), str.end());
	set<string> all_str;
	do
	{
		cout << str << endl;
		if (isValid(str))
			all_str.insert(str);
	} while (next_permutation(str.begin(), str.end()));

	map<string, int> m;
	for (int i = 0; i < len; i++)
	{
		auto it = s.begin() + i;
		string ss ;
		if (i == 0)
			ss = s.substr(1, len - 1);
		else if (i == len - 1)
			ss = s.substr(0, len - 1);
		else
			ss = s.substr(0, i) + s.substr(i + 1, len - 1 - i);
		cout << ss << endl;
		m[ss] = i;
	}

	/*for (auto it = all_str.begin(); it != all_str.end(); ++it)
		if (*it == s)
			all_str.erase(it);*/
	int count = 0;
	for (auto it = all_str.begin(); it != all_str.end(); ++it)
	{
		if (*it == s)
			continue;
		string temp = *it;
		for (int i = 0; i < len; i++)
		{
			auto it = temp.begin() + i;
			string ss;
			if (i == 0)
				ss = temp.substr(1, len - 1);
			else if (i == len - 1)
				ss = temp.substr(0, len - 1);
			else
				ss = temp.substr(0, i) + temp.substr(i + 1, len - 1 - i);
			if (m.find(ss) != m.end())
			{
				count++;
				break;
			}
		}
	}

	cout << count << endl;
	return 0;


}