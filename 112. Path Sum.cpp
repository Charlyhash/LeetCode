/*
leetcode 112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

��Ŀ���⣺���ڸ����Ķ������ж��Ƿ���һ���Ӹ��ڵ㵽�ӽڵ��·����ʹ�ø�·���ĺ͵��ڸ�����sum
����˼·��ֻ�践��true��false�����ֻҪ�ҵ���һ������ͷ��ء�

*/

#include "TreeInclude.h"
#include <queue>

class Solution 
{
public:
	//DFS
	bool hasPathSum1(TreeNode* root, int sum) 
	{
		if (!root)
			return false;
		if ( !root->left && !root->right && root->val == sum)
			return true;
		else
		{
			bool left = hasPathSum(root->left, sum - root->val);
			bool right = hasPathSum(root->right, sum - root->val);

			return (left | right);
		}

		return false;
	}
	//�ǵݹ�
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return false;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* cur;
		while (q.size())
		{
			int size = q.size();
			while (size--)
			{
				cur = q.front();
				q.pop();
				if (cur->left != NULL)
				{
					q.push(cur->left);
					cur->left->val += cur->val;
				}
				if (cur->right != NULL)
				{
					q.push(cur->right);
					cur->right->val += cur->val;
				}
				if (!cur->left && !cur->right && cur->val == sum)
					return true;
			}

		}

		return false;
	}
};

void TEST()
{
	Solution sol;
	vector<int> v{ 5,4,8,11,13,4,7,2,-1,-1,-1,1 };
	TreeNode* root = CreateTree(v);
	cout << sol.hasPathSum(root, 22) << endl;
	cout << sol.hasPathSum(root, 17) << endl;
}

int main()
{
	TEST();

	return 0;
}