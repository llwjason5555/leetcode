#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		set<vector<int>> s;
		sum(candidates, target, s);
		/*set<vector<int>> ret;
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			sort((*it).begin(), (*it).end());
			ret.insert(*it);
		}*/
		vector<vector<int>> res(s.begin(), s.end());
		return res;
	}

	void sum(vector<int> &candidates, int target, set<vector<int>> &res)
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

		for (int i = 0; i < candidates.size(); i++)
		{
			v.push_back(candidates[i]);
			sum(candidates, target - candidates[i], res);
			v.pop_back();

		}
		
	}
	vector<int> v;
};

int main()
{
	Solution so;
	vector<int> v= { 1,2 };
	int target = 4;
	cout << so.combinationSum(v, target).size() << endl;
	return 0;
}