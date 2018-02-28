#include<iostream>
#include<stack>
#include<vector>
#include<map>


using namespace std;

class Solution {
	typedef struct Node
	{
		int pos;
		int h;
		struct Node(int i, int j) :pos(i), h(j){}
	}Node;
public:
	int trap(int A[], int n) {
		stack<Node> st;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] && (st.empty() || A[i] < st.top().h))
			{
				Node node(i, A[i]);
				st.push(node);
			}
			else
			{
				if (!st.empty())
				{
					Node node = st.top()
				}
			}


		}
	}
};