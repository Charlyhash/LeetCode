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

��Ŀ���⣺�������������и��ڵ㵽Ҷ�ӽڵ��·��
����˼·��
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
		

		//���·����ջ
		stack<TreeNode*> stk;
		stk.push(root);
		//���·������
		vector<int> pathVal({root->val});
		//�Ƿ��Ѿ���������
		unordered_set<TreeNode*> umap;
		umap.insert(root);

		TreeNode* cur;
		while (stk.size())
		{
			cur = stk.top();
			//�������������Ϊ����
			//�ҵ�һ��·����ѹ�뷵�������У���������
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
					if (isLeft == umap.end())//û�з��ʹ�
					{
						//��ʼ���ʣ���ֵ�����ֵ�������У��ѽڵ�ŵ�ջ�У������Ϊ�ѷ���
						pathVal.push_back(cur->left->val);
						stk.push(cur->left);
						umap.insert(cur->left);
						continue;
					}
				}
				//�ܹ������˵��������Ϊ�ջ����������Ѿ����ʹ���
				//��Ϊ����Ҫÿ�η���һ��·������˲��ܰ�����·�������ˡ�
				if (cur->right)
				{
					auto isRight = umap.find(cur->right);
					if (isRight == umap.end())//û�з��ʹ�
					{
						//��ʼ���ʣ���ֵ�����ֵ�������У��ѽڵ�ŵ�ջ�У������Ϊ�ѷ���
						pathVal.push_back(cur->right->val);
						stk.push(cur->right);
						umap.insert(cur->right);
						continue;
					}
				}

				//������������������
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
		//�˳�����������������Ϊ��
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