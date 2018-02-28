#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		int len = words.size();
		if (len == 0)
			return words;

		vector<string> res;
		string line;
		int i = 0;
		while (i < len)
		{
			int n = 0;//文字长度
			int j = 0;//单词个数
			while (n+j-1 <= L&&i<len)
			{
				n = n + words[i].size();
				i++;
				j++;

			}
			
			if (n+j-1>L)
			{
				i--;
				j--;
				n = n - words[i].size();
			}
			

			if (j == 1 && i < len)
			{
				int length = L - n;
				string str(length, ' ');
				line = words[i - 1] + str;
				res.push_back(line);
				line.clear();
				continue;
			}
			if (i == len)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (k)
						line = line + words[i - (k + 1)] + " ";
					else
						line = line + words[i - (k + 1)];
				}
				res.push_back(line);
				line.clear();
				break;
			}
			int length = L - n;//空格长度
			int ave;//平均空格长度
			int left;//多余空格长度

			if (length)
			{
				 ave = length / (j - 1);
				 left = length % (j - 1);
			}
			string str(ave, ' ');
			for (int k = j-1; k>=0; k--)
			{
				if (k != 0)
					line = line + words[i-(k+1)] + str;
				else
					line = line + words[i-(k+1)];
				if (left)
				{
					line = line + " ";
					left--;
				}
			}
			res.push_back(line);
			line.clear();
			


		}
		return res;
	}
};

int main()
{
	vector<string> words = { "a","b","c","d","e." };
	Solution so;
	vector<string> res=so.fullJustify(words, 3) ;
	cout << res[0] << endl;
	cout << res[1] << endl;
	//string s(" ");
	//cout << s;
	return 0;
}