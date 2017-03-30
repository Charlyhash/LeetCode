/*
leetcode 53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

题目大意：找到和最大的子数组
解题思路：
扫描数组并求和，如果当前和>0则保留并且和最大和比较。
如果<0,则让当前和为0
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;
		int ret = INT_MIN;
		int curMax = 0;
		for (auto i : nums)
		{
			curMax += i;
			ret = std::max(curMax, ret);
			if (curMax < 0)
				curMax = 0;
		}
		return ret;
	}
};

void test()
{
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
}

int main()
{
	test();

	return 0;
}