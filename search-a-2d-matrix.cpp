#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int m = matrix.size();
		int n = matrix[0].size();
		if (n == 0)
			return false;

		int beg = 0;
		int end = m - 1;
		int row = -1;
		while (beg<=end)
		{
			int mid = (beg + end) / 2;
			if (matrix[mid][0] <= target&&matrix[mid][n - 1] >= target)
			{
				row = mid;
				break;
			}
			else if (target>matrix[mid][n - 1])
				beg = mid + 1;
			else if (matrix[mid][0]>target)
				end = mid - 1;

		}
		if (row == -1)
			row = beg;
		int b = 0;
		int e = n - 1;
		while (b<=e)
		{
			int mi = (b + e) / 2;
			if (matrix[row][mi] == target)
				return true;
			else if (matrix[row][mi]>target)
				e = mi - 1;
			else
				b = mi + 1;
		}

		return false;
	}
};

int main()
{
	vector <vector<int>> v = { { 1 } };
	Solution so;
	cout << so.searchMatrix(v, 7) << endl;
	return 0;

}