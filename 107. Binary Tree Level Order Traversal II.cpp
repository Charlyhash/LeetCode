/*
leetcode 107. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
	[15,7],
	[9,20],
	[3]
]

题目大意：层次遍历二叉树
解题思路：
1. 递归的方式递归打印每一层的节点，在打印下一层的节点。
2. 使用广度优先。使用队列，但是这里要确定如何换行，可以使用两个队列，一个存储本层节点，
一个存储下一层节点。当本层节点遍历完之后，需要交换两个队列。（另一种可以是在每次访问本
层节点时候，记录下一层节点个数，这样就知道已经换行了）

*/

#include "TreeInclude.h"
#include <algorithm>
#include <queue>

class Solution2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		int d = Depth(root);
		ret.resize(d);
		Recursive(root, ret, d-1);
		return ret;
	}

	int Depth(TreeNode* root)
	{
		if (!root)
			return 0;
		return (max(Depth(root->left), Depth(root->right)) + 1);
	}

	//用一个curLevel表示现在访问的层次
	//由于提前申请好空间了，可以直接使用ret
	void Recursive(TreeNode* root, vector<vector<int>>& ret, int curLevel) {
		if (root == NULL)
			return;
		ret[curLevel].push_back(root->val);
		Recursive(root->left, ret, curLevel - 1);
		Recursive(root->right, ret, curLevel - 1);
	}
};


//使用两个队列
class Solution1 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<int> v;
		queue<TreeNode*> q1, q2;
		q1.push(root);
		while (q1.size()) {
			while (q1.size()) {
				TreeNode* p = q1.front(); q1.pop();
				v.push_back(p->val);
				if (p->left)
					q2.push(p->left);
				if (p->right)
					q2.push(p->right);
			}
			ret.push_back(v);
			v.clear();
			swap(q1, q2);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<int> v;
		queue<TreeNode*> q1;
		int curCnt = 1; int nxtCnt = 0;
		q1.push(root);
		while (q1.size())
		{
			TreeNode* p = q1.front(); q1.pop();
			v.push_back(p->val);
			if (p->left)
			{
				++nxtCnt;
				q1.push(p->left);
			}
			if (p->right)
			{
				++nxtCnt;
				q1.push(p->right);
			}
			--curCnt;
			if (curCnt == 0)
			{
				curCnt = nxtCnt;
				nxtCnt = 0;
				ret.push_back(v);
				v.clear();
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};



void TEST()
{
	vector<int> v{ 3,9,20,-1,-1,15,7 };
	//vector<int> v{ 1,2,3,4,5 };
	TreeNode* root = CreateTree(v);

	Solution sol;
	vector<vector<int>> ret = sol.levelOrderBottom(root);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

}

int main()
{
	TEST();

	return 0;
}