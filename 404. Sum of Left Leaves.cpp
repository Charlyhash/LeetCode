/*
leetcode 404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.

��Ŀ���⣺���������Ҷ�ӽڵ�֮��
����˼·��
1. �ݹ飬������Ҷ�ӽڵ�����
2. BFS��
*/

#include "TreeInclude.h"
#include <queue>

class Solution1 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		return sumHelp(root);
	}

	int sumHelp(TreeNode* root)
	{
		if (!root)
			return 0;
		//�ýڵ����Ӵ��ڣ��������ӽڵ�
		if (root->left && !root->left->left && !root->left->right)
			return root->left->val + sumHelp(root->right);
		return sumHelp(root->left) + sumHelp(root->right);
	}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		
		int sum = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			TreeNode* cur = q.front();
			q.pop();
			if (cur->left)
			{
				if (!cur->left->left && !cur->left->right)
					sum += cur->left->val;
				else
					q.push(cur->left);
			}
			if (cur->right)
				q.push(cur->right);
		}

		return sum;

	}
};


void TEST()
{
	Solution sol;
	vector<int> v{ 3,9,20,-1,-1,15,7 };
	TreeNode* root = CreateTree(v);
	cout << sol.sumOfLeftLeaves(root) << endl;
}

int main()
{
	TEST();

	return 0;
}