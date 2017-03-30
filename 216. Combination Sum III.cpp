/*
leetcode 216. Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only 
numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Example 1:
	Input: k = 3, n = 7
	Output:
		[[1,2,4]]

Example 2:
	Input: k = 3, n = 9
	Output:
		[[1,2,6], [1,3,5], [2,3,4]]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int>> res;
		if (k == 0)
			return res;
		vector<int> tmp;
		DFS(res, tmp, k, n, 1);

		return res;
	}

	void DFS(vector<vector<int>>& res, vector<int>& tmp, int k, int n, int index)
	{
		if (k == 0 && n == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (int i = index; i < 10 && n >= i; ++i)
		{
			tmp.push_back(i);
			DFS(res, tmp, k-1, n - i, i + 1);
			tmp.pop_back();
		}
	}
};

void TEST()
{
	Solution sol;
	vector<vector<int>> ret = sol.combinationSum3(3, 9);

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