#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s;
		set<string> temp;
		vector<string> res;
		stack<char> st;
		vector<string> v;
		for (int i = 0; i < n; i++)
			s = s + "()";
		sort(s.begin(), s.end());
		do
		{
			//cout << s << endl;
			temp.insert(s);
		} while (next_permutation(s.begin(), s.end()));

		//cout << temp.size() << endl;
		for (auto it = temp.begin(); it != temp.end(); ++it)
		{
			string ss = *it;
			//cout << ss << endl;
			int i = 0;
			for (; i < ss.size(); i++)
			{
				if (ss[i] == '(')
					st.push(')');
				else if (st.empty())
					break;
				else
				{
					st.pop();
				}

			}
			if (i == ss.size())
				res.push_back(ss);
		}

		return res;
	}
};

int main()
{
	Solution so;
	vector<string> v = so.generateParenthesis(1);
	cout << v.size() << endl;
	//cout << v[0] << endl;
	return 0;
}
