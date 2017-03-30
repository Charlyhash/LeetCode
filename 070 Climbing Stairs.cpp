/*
70. Climbing Stairs  QuestionEditorial Solution  My Submissions
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

解题思路：
由于走到第n阶的最后一步，可以走一步或者两步，那么第n阶的步数等于第n-1阶步数+n-2阶步数。
dp[n] = dp[n-1]+dp[n-2]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) 
	{
		vector<int> dp(n+1, 0);
		if (n < 3)
			return n;
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}
	
	int climbStairs1(int n)
	{
		if (n < 3)
			return n;
		int pre1 = 2;	//前一个的数字(n-1)的step
		int pre2 = 1;	//n-2的step
		int ret = 0;
		int tmp = 0;
		for (int i = 3; i <= n; ++i)
		{
			ret = pre1 + pre2;
			//cout << ret << endl;
			tmp = pre1;	//更新pre1和pre2
			pre1 = ret;
			pre2 = tmp;
		}
		//cout << "---------------" << endl;
		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.climbStairs1(10) << endl;
}

int main()
{
	test();

	return 0;
}