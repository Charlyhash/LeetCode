/*
leetcode 101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
1
/ \
2   2
\   \
3    3

题目大意：判断给定的二叉树是不是对称的
解题思路：
1.递归：写一个函数判断两个子树是不是对称。
2.迭代，使用一个队列来存放二叉树中的节点。

*/

#include "TreeInclude.h"
#include <queue>

class Solution1 
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		else
			return SymmetricHelper(root->left, root->right);
	}

	bool SymmetricHelper(TreeNode* l, TreeNode* r)
	{
		if (!l && !r)
			return true;
		else if (!l || !r)
			return false;
		else if (l->val == r->val)
			return (SymmetricHelper(l->left, r->right)) && (SymmetricHelper(l->right, r->left));
		return false;
	}
};

class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);
		TreeNode *node1, *node2;
		while (q.size())
		{
			node1 = q.front(); q.pop();
			node2 = q.front(); q.pop();
			if (!node1 && !node2) continue;
			if (!node2 || !node1) return false;

			if (node1->val != node2->val)
				return false;
			q.push(node1->left); q.push(node2->right);
			q.push(node1->right); q.push(node2->left);
		}
		return true;
	}
};




void TEST()
{
	Solution sol;
	vector<int> v{ 1,2,2,3,4,4,3 };
	//vector<int> v{ 1,2,2,-1,3,-1,3 };
	TreeNode* root = CreateTree(v);
	cout << sol.isSymmetric(root) << endl;

}

int main()
{
	TEST();

	return 0;
}