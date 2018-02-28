#include<iostream>

using namespace std;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 class Solution {
 public:
	 bool isSymmetric(TreeNode *root) {
		 if (root == NULL)
			 return true;
		 bool flag = true;
		 solve(flag, root->left, root->right);
		 return flag;
	 }

	 void solve(bool &flag, TreeNode *leftnode, TreeNode *rightnode)
	 {
		 if ((leftnode&&rightnode == NULL) || (leftnode == NULL&&rightnode))
		 {
			 flag = false;
			 return;
		 }

		 if (leftnode == NULL&&rightnode == NULL)
			 return;

		 if (leftnode->val == rightnode->val)
		 {
			 solve(flag, leftnode->right, rightnode->left);
			 solve(flag, leftnode->left, rightnode->right);
		 }
		 else
		 {
			 flag = false;
			 return;
		 }
	 }
 };

 int main()
 {
	 Solution so;
	 TreeNode *root=new TreeNode(1);
	 TreeNode *leftnode = new TreeNode(2);
	 root->left = leftnode;
	 cout << so.isSymmetric(root) << endl;
	 return 0;
 }