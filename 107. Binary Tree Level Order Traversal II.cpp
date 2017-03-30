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

��Ŀ���⣺��α���������
����˼·��
1. �ݹ�ķ�ʽ�ݹ��ӡÿһ��Ľڵ㣬�ڴ�ӡ��һ��Ľڵ㡣
2. ʹ�ù�����ȡ�ʹ�ö��У���������Ҫȷ����λ��У�����ʹ���������У�һ���洢����ڵ㣬
һ���洢��һ��ڵ㡣������ڵ������֮����Ҫ�����������С�����һ�ֿ�������ÿ�η��ʱ�
��ڵ�ʱ�򣬼�¼��һ��ڵ������������֪���Ѿ������ˣ�

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

	//��һ��curLevel��ʾ���ڷ��ʵĲ��
	//������ǰ����ÿռ��ˣ�����ֱ��ʹ��ret
	void Recursive(TreeNode* root, vector<vector<int>>& ret, int curLevel) {
		if (root == NULL)
			return;
		ret[curLevel].push_back(root->val);
		Recursive(root->left, ret, curLevel - 1);
		Recursive(root->right, ret, curLevel - 1);
	}
};


//ʹ����������
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