/*
leetcode 39. Combination Sum

Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
	[7],
	[2, 2, 3]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
		vector<vector<int>> res;
		if (candidates.size() == 0)
			return res;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		DFS(res, tmp, candidates, target, 0);

		return res;
	}

private:
	void DFS(vector<vector<int>>& res, vector<int>& tmp, vector<int> candidates, int target, int start)
	{
		if (target == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (int i = start; i < candidates.size() && target >= candidates[i]; ++i)
		{
			tmp.push_back(candidates[i]);
			//target -= candidates[i];
			DFS(res, tmp, candidates, target-candidates[i], i);
			tmp.pop_back();
		}
	}
};

void TEST()
{
	vector<int> candidates{ 2,3,6,7 };
	Solution sol;
	vector<vector<int>> ret = sol.combinationSum(candidates, 7);

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