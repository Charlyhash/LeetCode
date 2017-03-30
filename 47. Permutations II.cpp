/*
leetcode 47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
	[1,1,2],
	[1,2,1],
	[2,1,1]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		vector<vector<int>> ret;
		if (nums.size() == 0)
			return ret;

		vector<int> visited;
		vector<bool> isVisited(nums.size(), false);//存放nums[i]是否访问过的数组
		sort(nums.begin(), nums.end());//先排序：这样就很方便看是不是已经使用这个元素排序了

		DFS(ret, visited, isVisited,nums);

		return ret;
	}

	void DFS(vector<vector<int>>& ret, vector<int>& visited, vector<bool> isVisited, vector<int>& nums)
	{
		if (visited.size() == nums.size())
		{
			ret.push_back(visited);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			//重复元素忽略
			//只要前一个元素没有访问过并且和前一个元素相等，说明在排序
			//前一个元素时已经有了这种情况
			if (i > 0 && !isVisited[i-1] && nums[i] == nums[i-1])
				continue;
			if (!isVisited[i])
			{
				visited.push_back(nums[i]);
				isVisited[i] = true;
				DFS(ret, visited,isVisited, nums);
				visited.pop_back();
				isVisited[i] = false;
			}
		}

	}
};

void TEST()
{
	Solution sol;
	vector<int> v{ 1,1,2 };
	vector<vector<int>> ret = sol.permuteUnique(v);

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