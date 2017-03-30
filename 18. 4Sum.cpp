/*
leetcode 18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets 
in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
	[-1,  0, 0, 1],
	[-2, -1, 1, 2],
	[-2,  0, 0, 2]
]

题目大意：对于给定的数组里面的树，计算4个不同的数相加的和为target
解题思路：转化为3Sum，先固定两个数，然后找两个数的和为target-nums[i]-nums[j]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		int len = nums.size();
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 3; ++i)
		{
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			for (int j = i + 1; j < len - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j-1])
					continue;
				int target2 = target - nums[i] - nums[j];
				int low = j + 1;
				int high = len - 1;
				while (low < high)
				{
					int tmp = nums[low] + nums[high];
					if (tmp > target2)
						--high;
					else if (tmp < target2)
						++low;
					else
					{
						ret.push_back({ nums[i], nums[j], nums[low], nums[high] });
						int k = low + 1;
						while (k < high && nums[k] == nums[low])
							++k;
						low = k;

						k = high - 1;
						while (k > low && nums[k] == nums[high])
							--k;
						high = k;
					}
				}

			}
		}

		return ret;
	}

	//简单优化后：
	vector<vector<int>> fourSum1(vector<int>& nums, int target)
	{
		vector<vector<int>> ret;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 3; ++i)
		{
			//avoid dumplicate value
			if (i > 0  && nums[i]== nums[i-1])
				continue;
			if (nums[i] + nums[len-1] + nums[len-2] + nums[len-3] < target)
				continue;
			if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
				break;
			for (int j = i + 1; j < len - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target)
					continue;
				if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
					break;
				int low = j + 1; 
				int high = len - 1;
				while (low < high)
				{
					int sum = nums[i] + nums[j] + nums[low] + nums[high];
					if (sum < target)
						++low;
					else if (sum > target)
						--high;
					else
					{
						ret.push_back({ nums[i], nums[j], nums[low], nums[high] });
						do
						{
							++low;
						} while (nums[low] == nums[low-1] && low < high);
						do
						{
							--high;
						} while(nums[high] == nums[high + 1] && low < high);
					}
				}
			}

		}

		return ret;
	}

	//用hash map,key为两个数的和，value为两个数的下标的数组。
	//
	vector<vector<int>> fourSum2(vector<int>& nums, int target)
	{
		vector<vector<int>> ret;
		if (nums.size() < 4)
			return ret;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		unordered_map<int, vector<pair<int, int>>> umap;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + i; j < len; ++j)
				umap[nums[i] + nums[j]].push_back({ i, j });
		}

		for (int i = 0; i < len-3; ++i)
		{
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			for (int j = i + 1; j < len-2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j-1])
					continue;
				int target1 = target - nums[i] - nums[j];
				if (umap.find(target1) != umap.end())
				{
					bool isFirstPush = true;
					//找到另外两个数
					vector<pair<int, int>> tmp = umap[target1];
					for (int k = 0; k < tmp.size(); ++k)
					{
						if (tmp[k].first <= j)
							continue;
						//要避免是同样数，要么是第一次push，要么有序对pair的第一个数不同。
						if (isFirstPush || (ret.back())[2] != nums[tmp[k].first])
						{
							ret.push_back({ nums[i], nums[j], nums[tmp[k].first], nums[tmp[k].second] });
							isFirstPush = false;
						}
					}

				}
			}
		}

		return ret;
	}
};

void test()
{
	vector<int> s{ 1,0,-1,0,-2,2 };
	Solution sol;
	vector<vector<int>> ret = sol.fourSum2(s, 0);

	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

}

int main()
{
	test();

	return 0;
}