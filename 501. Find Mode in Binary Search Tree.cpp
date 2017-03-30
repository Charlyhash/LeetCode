/*
leetcode 501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) 
(the most frequently occurred element) in the given BST.

题目大意：对于BST树，给出出现次数最多的元素
解题思路：
1. 遍历一遍，用map记录元素和出现的次数，并记录出现的做多次数，然后遍历map
2. 中序遍历并递归
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "TreeInclude.h"

using namespace std;

class Solution1 
{
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		map<int, int> mmap;
		int maxCount = 0;
		Traverse(root, mmap, maxCount);
		for (auto iter = mmap.begin(); iter != mmap.end(); ++iter)
		{
			if (iter->second == maxCount)
				ret.push_back(iter->first);
		}

		return ret;
	}

	void Traverse(TreeNode* root, map<int, int>& mmap, int& maxCount)
	{
		if (root == NULL)
			return;
		int count = ++mmap[root->val];
		maxCount = max(maxCount, count);
		Traverse(root->left, mmap, maxCount);
		Traverse(root->right, mmap, maxCount);
	}
};

class Solution
{
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> ret; //return reslut;
		if (root == NULL)
			return ret;
		int curVal=0x7fffffff, MaxCnt = 0, curCnt = 0;
		//Inorder(root, ret)
		Inorder(root, ret, curVal, MaxCnt, curCnt);

		return ret;
	}

	/*
	参数说明：
	root-根节点
	ret-保存的出现次数最多的
	curVal-当前遍历的值
	MaxCnt-最多出现的次数
	curCnt-当前出现的次数
	记录当前元素和其出现的次数。如果root->val等于当前元素值，curCnt+1,不等，则是第一次出现
	如果当前元素出现次数curCnt>MaxCnt,那么清空ret,并将curVal压入，如果等于，则直接压入curVal
	*/
	void Inorder(TreeNode* root, vector<int>& ret, int& curVal, int& MaxCnt, int& curCnt)
	{
		if (root == NULL)
			return;
		Inorder(root->left, ret, curVal, MaxCnt, curCnt);

		if (root->val == curVal)
			++curCnt;
		else
		{
			curCnt = 1;
			curVal = root->val;
		}
		if (curCnt > MaxCnt)
		{
			ret.clear();
			ret.push_back(curVal);
			MaxCnt = curCnt;
		}
		else if (curCnt == MaxCnt)
		{
			ret.push_back(curVal);
		}

		Inorder(root->right, ret, curVal, MaxCnt, curCnt);
	}

};

void TEST()
{
	vector<int> v{ 1,-1,2,-1,-1, 2 };
	TreeNode* root = CreateTree(v);
	//FirstOrderTraverse(root);
	//cout << endl;
	Solution sol;
	vector<int> ret = sol.findMode(root);

	for (auto v : ret)
		cout << v << " ";
	cout << endl;
} 

int main()
{
	TEST();

	return 0;
}