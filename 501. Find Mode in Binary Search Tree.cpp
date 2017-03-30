/*
leetcode 501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) 
(the most frequently occurred element) in the given BST.

��Ŀ���⣺����BST�����������ִ�������Ԫ��
����˼·��
1. ����һ�飬��map��¼Ԫ�غͳ��ֵĴ���������¼���ֵ����������Ȼ�����map
2. ����������ݹ�
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
	����˵����
	root-���ڵ�
	ret-����ĳ��ִ�������
	curVal-��ǰ������ֵ
	MaxCnt-�����ֵĴ���
	curCnt-��ǰ���ֵĴ���
	��¼��ǰԪ�غ�����ֵĴ��������root->val���ڵ�ǰԪ��ֵ��curCnt+1,���ȣ����ǵ�һ�γ���
	�����ǰԪ�س��ִ���curCnt>MaxCnt,��ô���ret,����curValѹ�룬������ڣ���ֱ��ѹ��curVal
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