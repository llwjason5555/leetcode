#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		int m = board.size();
		int len = word.size();
		if (len == 0)
			return true;
		if (m == 0 && len>0)
			return false;
		int n = board[0].size();
		if (m*n<len)
			return false;

		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (board[i][j] == word[0])
				{
					int m_path = 0, n_path = 0;
					int k;
					for (k = 1; k<len; k++)
					{

						if ((i + 1<m&&board[i + 1][j] == word[k]) || (j + 1<n&&board[i][j + 1] == word[k]))
						{
							if (i + 1<m&&board[i + 1][j] == word[k])
							{
								i++;
								m_path++;
							}
							else
							{
								j++;
								n_path++;
							}
						}
						else
							break;
					}
					if (k == len)
						return true;
					i = i - m_path;
					j = j - n_path;
				}
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<char>> v = { { 'C', 'A', 'A' }, { 'A', 'A', 'A' }, { 'B', 'C', 'D' } };
	string word = "AAB";
	Solution so;
	cout << so.exist(v, word) << endl;
	return 0;
}