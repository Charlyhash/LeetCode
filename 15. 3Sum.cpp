/*
leetcode 15. 3Sum

Given an array S of n integers, are there elements a, b, c 
in S such that a + b + c = 0? Find all unique triplets 
in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
Subscribe to see which companies asked this question

题目大意：从给定的数中找到3个数的和为0
解题思路：固定一个数后转为2Sum
1.先对数组排序
2.扫描数组，对于每一个数，相当于求后面数的2Sum，target为0-nums[i]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int i = 0; i < len - 2; ++i)
		{
			//不考虑重复的元素
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int target1 = 0 - nums[i];
			twoSum(nums, i + 1, target1, ret);
		}

		return ret;
	}

	//转化为2Sum。开始位置为start,和应该为targer
	//数组为nums,把结果存放在ret中。
	void twoSum(vector<int>& nums, int start, int target, vector<vector<int>>& ret)
	{
		int low = start;
		int high = nums.size() - 1;
		//找到和为target的两个数。因为是已经排好序的数组，可以直接从前面和后面相加开始查找。
		//要找到所有和为target的两个数才完成。
		while (low < high)
		{
			int tmp = nums[low] + nums[high];
			if (tmp < target)
				++low;
			else if (tmp > target)
				--high;
			else
			{
				ret.push_back(vector<int>{nums[start - 1], nums[low], nums[high]});

				//避免重复
				int k = low + 1;
				while(k < high && nums[k] == nums[low])
					++k;
				low = k;
				k = high - 1;
				while (k > low && nums[k] == nums[high])
					k--;
				high = k;
			}
		}
	}
};

void test()
{
	vector<int> v{ -1, 0, 1, 2, -1, -4 };
	Solution sol;
	vector<vector<int>> ret = sol.threeSum(v);
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