/*
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]
Subscribe to see which companies asked this question.

题目大意：求所给集合的子集
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) 
	{
		
		vector<vector<int>> ret;
		if (nums.size() == 0)
			return ret;
		sort(nums.begin(), nums.end());
		vector<int> tmp; int count = 0;
		ret.push_back(tmp);
		DFS(ret, nums, tmp, 0);

		return ret;
	}

	void DFS(vector<vector<int>>& ret, vector<int>& nums, vector<int> tmp, int pos)
	{
		for (int i = pos; i < nums.size(); ++i)
		{
			tmp.push_back(nums[i]);
			ret.push_back(tmp);
			DFS(ret, nums, tmp, i + 1);
			tmp.pop_back();
		}
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{ 1,2,3};
	vector<vector<int>> ret = sol.subsets(nums);
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