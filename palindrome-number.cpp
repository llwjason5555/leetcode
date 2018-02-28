#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			x = -x;
		int n = 1;
		int y;
		while (x / 10)
			n++;
		if (n == 1)
			return true;
		if (n % 2 == 0)
		{
			y = x%(int)pow(10.0, n / 2);
			x = x / (int)pow(10.0, n / 2);
			int d = 0;
			for (int i = 0; i<n / 2; i++)
				d = d + 1 * (int)pow(10.0, i);
			if ((x + y) % d == 0)
				return true;
			else
				return false;
		}
		else
		{
			y = x%(int)pow(10.0, n / 2);
			x = x/(int)pow(10.0, n / 2 + 1);
			int d = 0;
			for (int i = 0; i<n / 2; i++)
				d = d + 1 * (int)pow(10.0, i);
			if ((x + y) % d == 0)
				return true;
			else
				return false;
		}
	}
};

int main()
{
	Solution so;
	int n = 123321;
	cout << so.isPalindrome(n) << endl;;
	return 0;
}