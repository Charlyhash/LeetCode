/*
leetcode 62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 3 x 7 grid. How many possible unique paths are there?
Note: m and n will be at most 100.

解题思路：动态规划
用dp[i][j]表示到(i,j)位置的步数，那么:
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
注意边界：当i==0||j==0时，dp[i][j] = 1
*/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		vector<vector<int>> dp;
		dp.resize(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
		
		return dp[m - 1][n - 1];
	}

	//优化：节省空间
	int uniquePaths1(int m, int n)
	{
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				dp[j] = dp[j] + dp[j - 1];//第i行第j列的步数之和
		
		return dp[n-1];
	}
};

void test()
{
	Solution sol;
	
	cout << sol.uniquePaths(2, 3) << endl;
	cout << sol.uniquePaths1(2, 3) << endl;
}

int main()
{
	test();

	return 0;
}