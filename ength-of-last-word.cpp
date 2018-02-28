#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (strlen(s) == 0)
			return 0;
		//string ss(s);
		stack<char> st;
		for (int i = 0; i<strlen(s); i++)
			st.push(s[i]);
		int count = 0;
		while (st.top() != ' ')
		{
			count++;
			st.pop();
		}
		return count;
	}
};

int main()
{
	Solution so;
	char s[] = "Hello world";
	cout << so.lengthOfLastWord(s) << endl;
	return 0;
}