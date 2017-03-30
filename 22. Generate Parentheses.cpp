/*
leetcode 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.
For example, given n = 3, a solution set is:

[
	"((()))",
	"(()())",
	"(())()",
	"()(())",
	"()()()"
]

��Ŀ���⣺���ڸ���������n�������ַ������飬ÿ���ַ�������n������
����˼·������
�õݹ飬ÿ�εݹ��ʱ�����ʣ����������ŵ���Ŀ��Ȼ��������ѡ�񣬷������Ż���������
ע�⣺�����Ų��ܴ��������š�
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> ret;
		if (n == 0)
			return ret;
		DFS(ret, n, n, "");

		return ret;
	}

	void DFS(vector<string>& ret, int left, int right, string str)
	{
		if (right < left)
			return;
		if (left == 0 && right == 0)
			ret.push_back(str);
		if (left > 0)
			DFS(ret, left - 1, right, str + "(");
		if (right > 0)
			DFS(ret, left, right - 1, str + ")");
	}
};

void TEST()
{
	Solution sol;
	vector<string> ret;
	ret = sol.generateParenthesis(3);

	for (auto str : ret)
		cout << str << endl;

}

int main()
{
	TEST();

	return 0;
}