/*
leetcode 300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], 
therefore the length is 4. Note that there may be more than one LIS combination, 
it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

������������dp[i]��ʾ��nums[i]��β�������е�LIS
״̬ת�Ʒ��̣�dp[i]=max(dp[j]+1, dp[i]);����jӦ�����㣺0<=j<i����nums[j]<nums[i]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		int len = nums.size();
		if (len == 0 || len == 1)
			return len;
		vector<int> dp(len, 1);
		//dp[0] = 1;
		int res = 1;	//����ֵ����������dp[i];
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if ((nums[i] > nums[j]) && (dp[i] < dp[j] + 1))
					dp[i] = dp[j] + 1;
			}
			res = max(res, dp[i]);
		}

		return max(res, dp[len - 1]);
	}
};

void test()
{

}

int main()
{
	test();

	return 0;

}