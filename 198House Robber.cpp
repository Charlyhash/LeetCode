/*
leetcode 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses
have security system connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

解题思路：dp

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (size_t i = 2; i < nums.size(); ++i)
		{
			dp[i] = max(dp[i-1], dp[i-2]+nums[i]);//dp[i-1]:不抢这一家，dp[i-2]+nums[i]:抢这一家。
			//cout << dp[i] << " ";
		}
		//cout << endl;
		return dp[nums.size() - 1];
	}
	//空间优化
	int rob1(vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		int pre = 0;	//对于i房间来说，保存的是前一个的最优解
		int cur = 0;	//对于i房间来说，保存的是当前最优解
		int tmp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			tmp = cur;//临时存放上一个(i-1时)当前的最优解
			cur = max(nums[i] + pre, cur);//当前最优解
			pre = tmp;//前一个最优解
		}

		return cur;
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{ 5,1,3,5,2,3,4,6,7 };
	cout << sol.rob1(nums) << endl;
}

int main()
{
	TEST();

	return 0;
}