#include<iostream>

using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		if (n == 0)
			return -1;
		int beg = 0, end = n - 1, mid ;
		while (beg <= end)
		{
			mid = (beg + end) / 2;
			if (target == A[mid])
				return mid;
			else
			{
				if (target < A[mid])
				{
					if (A[end]<A[beg])
					{
						if (target == A[end])
							return end;
						else if (target > A[end])
						{
							end = mid - 1;
						}
						else
							beg = mid + 1;
					}
					else
						end = mid - 1;
					
				}
				else
					beg = mid + 1;
			}
		}
		return -1;
	}
};

int main()
{
	int A[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	int n = 8;
	Solution so;
	cout << so.search(A, n, 2) << endl;
	return 0;
}