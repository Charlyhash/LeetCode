/*
leetcode 110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined 
as a binary tree in which the depth of the two subtrees of 
every node never differ by more than 1.

题目大意：判断一个树是不是平衡树
解题思路：
1. 先求一颗树的辅助函数DepthMax()求解最大高度,然后对每一个节点，判断其左右子树是否平衡
2. DFS.

*/

#include "TreeInclude.h"

class Solution1 {
public:
	bool isBalanced(TreeNode* root) 
	{
		if (root == NULL)
			return true;
		if (abs(DepthMax(root->left)-DepthMax(root->right)) > 1)
			return false;

		return isBalanced(root->left) && isBalanced(root->right);
	}

	int DepthMax(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return 1 + max(DepthMax(root->left), DepthMax(root->right));
	}
};

//DFS:至下而上
class Solution {
private:
	bool flag;
public:
	bool isBalanced(TreeNode* root)
	{
		if (!root)
			return true;
		flag = true;
		DFS(root, 1);
		return flag;
	}

	int DFS(TreeNode* root, int depth)
	{
		if (!flag)
			return 0;
		if (!root->left && !root->right)
			return depth;
		int left = depth;
		int right = depth;
		if (root->left)
			left = DFS(root->left, depth + 1);
		if (root->right)
			right = DFS(root->right, depth + 1);
		if (abs(left - right) > 1)
			flag = false;

		return max(left, right);

	}
	
};

void TEST()
{
	Solution sol;
	vector<int> v{ 3,-1,20,-1,-1,15,7 };
	TreeNode* root = CreateTree(v);
	cout << sol.isBalanced(root) << endl;
}

int main()
{
	TEST();

	return 0;
}