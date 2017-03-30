/*
leetcode 111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

题目大意：求解二叉树的最短路径
解题思路：
*/

#include "TreeInclude.h"
#include <queue>

class Solution {
public:
	//DFS
	int minDepth1(TreeNode* root) 
	{
		if (!root)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (!root->left)
			return 1+right;
		if (!root->right)
			return 1+left;
		return 1 + min(left, right);
	}

	//BFS:层次遍历，用计数的方法分层次
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ret = 1;
		int curLevel = 1;
		int nextLevel = 0;
		while (q.size())
		{
			TreeNode* cur = q.front();
			q.pop();
			curLevel--;
			if (!cur->left && !cur->right)
				return ret;
			if (cur->left)
			{
				q.push(cur->left);
				++nextLevel;
			}
			if (cur->right)
			{
				q.push(cur->right);
				++nextLevel;
			}
			if (curLevel == 0)
			{
				curLevel = nextLevel;
				nextLevel = 0;
				++ret;
			}
		}

		return ret;
	}
};

void TEST()
{
	Solution sol;
	vector<int> v{1,2,3,4,-1,-1,5};
	TreeNode* root = CreateTree(v);
	cout << sol.minDepth(root) << endl;
}

int main()
{
	TEST();

	return 0;
}