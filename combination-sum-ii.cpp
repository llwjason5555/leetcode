#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		set<vector<int>> s;
		sum(num, target, s,0);
		vector<vector<int>> res(s.begin(), s.end());
		return res;
	}

	void sum(vector<int> &candidates, int target, set<vector<int>> &res,int beg)
	{
		vector<int> temp;
		if (target == 0)
		{
			temp = v;
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		else if (target < 0)
			return;

		for (int i = beg; i < candidates.size(); i++)
		{
			v.push_back(candidates[i]); 
			sum(candidates, target - candidates[i], res,i+1);
			v.pop_back();

		}

	}
	vector<int> v;
};

int main()
{
	Solution so;
	vector<int> v = { 1,2 };
	int target = 4;
	cout << so.combinationSum2(v, target).size() << endl;
	return 0;
}