#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		int len1 = S.size();
		int len2 = T.size();
		if (len1 == 0 || len2 == 0 || len1 < len2)
			return string("");
		string res;
		map<char, int> m;
		vector<int> v(len2, 0);

		for (int i = 0; i < len2; i++)
			m[T[i]] = i;

		int beg = 0, end = 0;
		int count = 0;
		while (1)
		{
			if (m.find(S[end]))
		}
	
	}
};