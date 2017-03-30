/*
LeetCode 077Combinations 递归/回溯
题目大意：给两个数n和k,找出1-n这n个数的个数为k的子序列
解题思路：递归/回溯
参考：http://blog.csdn.net/charles1e/article/details/51646879
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) 
	{
		vector<vector<int> > result;
		vector<int> path;
		DFS(n, k, 1, 0, path, result);
		return result;
	}

private:
	//长度为n,要找到长度为k的子序列，起始位置为start,当前个数为cur
	//path记录的是一个子序列，result记录的是整个结果
	void DFS(int n, int k, int start, int cur, vector<int>& path, vector<vector<int> > &result)
	{
		if (cur == k)
		{//递归出口：path中已经有了k个数
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			path.push_back(i);
			DFS(n, k, i + 1, cur + 1, path, result);	//递归：添加下一个元素
			path.pop_back();							//回溯，弹出当前元素后继续查找
		}
	}
};

int main()
{
	Solution sol;
	int n, m;
	cin >> n >> m;

	vector<vector<int> > result;
	result = sol.combine(n, m);

	for (auto v : result)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
/*
输入：
4 2
输出：
4 2
1 2
1 3
1 4
2 3
2 4
3 4
*/