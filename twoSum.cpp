#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> m;
		vector<int> ret;
		for (int i = 0; i < numbers.size(); i++)
			m[numbers[i]] = i;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (m.find(target - numbers[i]) != m.end() && m[target - numbers[i]]>i)
			{
				ret.push_back(i + 1);
				ret.push_back(m[target - numbers[i]] + 1);
				break;
			}
		}
		return ret;
	}
};