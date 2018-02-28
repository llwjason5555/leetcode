#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int i = 0, j = 0, num = 1;
		while (num<n*n + 1)
		{

			while (j<n&&res[i][j] == 0)
			{
				res[i][j] = num;
				j++;
				num++;
			}
			j--;
			i++;
			while (i<n&&res[i][j] == 0)
			{
				res[i][j] = num;
				i++;
				num++;
			}
			i--;
			j--;
			while (j >= 0 && res[i][j] == 0)
			{
				res[i][j] = num;
				j--;
				num++;
			}
			j++;
			i--;
			while (i >= 0 && res[i][j] == 0)
			{
				res[i][j] = num;
				i--;
				num++;
			}
			i++;
			j++;

		}
		return res;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> res = so.generateMatrix(4);
	cout << res.size() << endl;
	return 0;
}