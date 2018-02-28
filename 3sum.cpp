#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		
		vector<vector<int>> res;
		vector<int> v;
		if (num.size() == 0)
			return res;
		map<int, int> m;

		sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); i++)
			m[num[i]] = i;

		for (int i = 0; i < num.size()-1; i++)
			for (int j = i + 1; j < num.size();j++)
				if (m.find(-(num[i] + num[j])) != m.end() && m[-(num[i] + num[j])] > j)
				{
					v.push_back(num[i]);
					v.push_back(num[j]);
					v.push_back(-(num[i] + num[j]));
					res.push_back(v);
					v.clear();
				}
		return res;
	}
};