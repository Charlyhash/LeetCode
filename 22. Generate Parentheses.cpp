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

题目大意：对于给定的数字n，返回字符串数组，每个字符串包含n对括号
解题思路：回溯
用递归，每次递归的时候计算剩余的左右括号的数目，然后有两中选择，放左括号或者右括号
注意：左括号不能大于右括号。
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