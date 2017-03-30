#ifndef _TREE_INCLUDE_H_ 
#define _TREE_INCLUDE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 节点数据结构
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//使用数组创建二叉树
void CreateNode(const vector<int>& v, TreeNode* cur, int curIndex)
{
	int len = v.size();
	if (len == 0 || cur == NULL || curIndex < 0 || curIndex >= len)
		return;

	if ((2 * curIndex + 1 < len) && (v[2*curIndex+1] != -1))
	{
		TreeNode* tmp = new TreeNode(v[2 * curIndex + 1]);
		cur->left = tmp;
	}
	else
		cur->left = NULL;
	if ((2 * curIndex + 2 < len) && (v[2*curIndex+2] != -1))
	{
		TreeNode* tmp = new TreeNode(v[2 * curIndex + 2]);
		cur->right = tmp;
	}
	else
		cur->right = NULL;
	CreateNode(v, cur->left, 2 * curIndex + 1);
	CreateNode(v, cur->right, 2 * curIndex + 2);
}

TreeNode* CreateTree(const vector<int>& v)
{
	int len = v.size();
	if (len == 0)
		return NULL;

	TreeNode* root = new TreeNode(v[0]);
	CreateNode(v, root, 0);

	return root;
}

void FirstOrderTraverse(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";
	FirstOrderTraverse(root->left);
	FirstOrderTraverse(root->right);
	//cout << endl;
}

void MakeEmpty(TreeNode* root)
{
	if (root != NULL)
	{
		MakeEmpty(root->left);
		MakeEmpty(root->right);
		delete root;
	}
}

#endif // 
