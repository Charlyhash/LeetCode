/*
leetcode 264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

解题思路：DP


dp[i]= mim(dp[t2]*2,dp[t3]*3, dp[t5]*5)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) 
	{
		vector<int> dp(n,0);
		int t2 = 2;			//dp[i]*2
		int t3 = 3;			//dp[i]*3
		int t5 = 5;			//dp[i]*5
		//下标
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;
		dp[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			dp[i] = ThreeMin(t2, t3, t5);
			if (dp[i] == t2)
				t2 = dp[++index2]*2;
			if (dp[i] == t3)
				t3 = dp[++index3]*3;
			if (dp[i] == t5)
				t5 = dp[++index5]*5;
		
			//cout << dp[i] << endl;
		}

		return dp[n - 1];
	}

private:
	int ThreeMin(int i, int j, int k)
	{
		return min(min(i, j), k);
	}
};

void test()
{
	Solution sol;
	cout << sol.nthUglyNumber(100) << endl;
}

int main()
{
	test();

	return 0;
}