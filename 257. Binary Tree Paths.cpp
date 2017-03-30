/*
leetcode 257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:

  1
/   \
2    3
\
 5
All root-to-leaf paths are:["1->2->5", "1->3"]

题目大意：求解二叉树中所有根节点到叶子节点的路径
解题思路：
*/

#include "TreeInclude.h"
#include <unordered_set>
#include <stack>

class Solution
{
public:
	//iterator
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> ret;
		if (!root)
			return ret;
		

		//存放路径的栈
		stack<TreeNode*> stk;
		stk.push(root);
		//存放路径的数
		vector<int> pathVal({root->val});
		//是否已经遍历过了
		unordered_set<TreeNode*> umap;
		umap.insert(root);

		TreeNode* cur;
		while (stk.size())
		{
			cur = stk.top();
			//如果左右子树都为空则：
			//找到一条路径，压入返回数组中；继续回溯
			if (!cur->left && !cur->right)
			{
				ret.push_back(GenHelper(pathVal));
				pathVal.pop_back();
				stk.pop();
			}
			else 
			{
				if (cur->left) 
				{
					auto isLeft = umap.find(cur->left);
					if (isLeft == umap.end())//没有访问过
					{
						//开始访问：把值存放在值得数组中，把节点放到栈中，并标记为已访问
						pathVal.push_back(cur->left->val);
						stk.push(cur->left);
						umap.insert(cur->left);
						continue;
					}
				}
				//能够到这里：说明左子树为空或者左子树已经访问过了
				//因为我们要每次访问一条路径，因此不能把两条路径混杂了。
				if (cur->right)
				{
					auto isRight = umap.find(cur->right);
					if (isRight == umap.end())//没有访问过
					{
						//开始访问：把值存放在值得数组中，把节点放到栈中，并标记为已访问
						pathVal.push_back(cur->right->val);
						stk.push(cur->right);
						umap.insert(cur->right);
						continue;
					}
				}

				//左右子树都访问完了
				pathVal.pop_back();
				stk.pop();
			}
		}

		return ret;
	}

	string GenHelper(vector<int> v)
	{
		int len = v.size();
		string ret;
		if (len == 0)
			return ret;
		ret += to_string(v[0]);
		for (int i = 1; i < len; ++i)
			ret += ("->" + to_string(v[i]));

		return ret;
	}
};

class Solution1
{
public:
	//recusive
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> ret;
		if (!root)
			return ret;

		FindHelp(ret, root, to_string(root->val));

		return ret;
	}

	void FindHelp(vector<string>& ret, TreeNode* root, string str)
	{
		//退出条件：左右子树都为空
		if (!root->left && !root->right)
		{
			ret.push_back(str);
			return;
		}

		if (root->left)
		{
			FindHelp(ret, root->left, str + "->" + to_string(root->left->val));
		}

		if (root->right)
		{
			FindHelp(ret, root->right, str + "->" + to_string(root->right->val));
		}
	}
};

void TEST()
{
	Solution sol;
	vector<int> v{ 1,2,3,-1,5 };
	TreeNode* root = CreateTree(v);
	vector<string> ret = sol.binaryTreePaths(root);

	for (auto str : ret)
		cout << str << endl;
}

int main()
{
	TEST();

	return 0;

}