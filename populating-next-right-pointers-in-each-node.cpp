#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<TreeLinkNode*> v;
			while (!q.empty())
			{
				v.push_back(q.front());
				q.pop();
			}

			if (v.size() == 0)
				break;

			for (int i = 0; i<v.size() - 1; i++)
			{
				if (v[i]->left)
					q.push(v[i]->left);
				if (v[i]->right)
					q.push(v[i]->right);
				v[i]->next = v[i + 1];
			}
			if (v[v.size() - 1]->left)
				q.push(v[v.size() - 1]->left);
			if (v[v.size() - 1]->right)
			q.push(v[v.size() - 1]->right);
			v[v.size() - 1]->next = NULL;
		}
	}


};


int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *root1 = new TreeLinkNode(2);
	TreeLinkNode *root2 = new TreeLinkNode(3);
	root->left = root1;
	root->right = root2;
	Solution so;
	so.connect(root);
	return 0;

}