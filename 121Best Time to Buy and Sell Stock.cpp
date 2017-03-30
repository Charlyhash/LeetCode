/*
leetcode 121. Best Time to Buy and Sell Stock

ay you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

解题思路：
用dp[i]表示prices[0...i]的最大利润，minPrice是prices[0...i-1]的最小值，
那么：dp[i] = max{dp[i-1], prices[i]-minPrice}
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() == 0)
			return 0;
		int minPrice = prices[0];		//0...i的最低价格
		vector<int> dp(prices.size(), 0);	//dp[i]为0...i的最大利润
		dp[0] = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i] - minPrice > dp[i - 1])	//计算dp[i]
				dp[i] = prices[i] - minPrice;
			else
				dp[i] = dp[i - 1];
			if (prices[i] < minPrice)		//更新minPrice
				minPrice = prices[i];
		}

		return dp[prices.size()-1];
	}
};

void test()
{
	vector<int> nums{ 7, 1, 5, 3, 6, 4 };
	vector<int> nums1{ 7, 6, 4, 3, 1 };
	Solution sol;
	cout << sol.maxProfit(nums) << endl;
	cout << sol.maxProfit(nums1) << endl;
}

int main()
{
	test();

	return 0;
}