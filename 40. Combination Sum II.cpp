/*
leetcode 40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all 
unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
	[1, 7],
	[1, 2, 5],
	[2, 6],
	[1, 1, 6]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;

		DFS(res, candidates, tmp, target, 0);

		return res;
 	}

	void DFS(vector<vector<int>>& res, vector<int>& candidates, vector<int>& tmp, int target, int start)
	{
		if (target == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (int i = start; i < candidates.size() && target >= candidates[i]; ++i)
		{
			//和第一个数是可以重复的，后面的不能重复
			if (i > start && candidates[i] == candidates[i-1])
				continue;
			tmp.push_back(candidates[i]);
			DFS(res, candidates, tmp, target - candidates[i], i+1);
			tmp.pop_back();
		}
	}
};

void TEST()
{
	Solution sol;
	//vector<int> candidates{10,1,2,7,6,1,5};
	//vector<vector<int>> ret = sol.combinationSum2(candidates, 8);
	vector<int> candidates{ 1 };
	vector<vector<int>> ret = sol.combinationSum2(candidates, 1);

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

