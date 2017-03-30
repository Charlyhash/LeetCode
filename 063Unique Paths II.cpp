/*
leetcode 63. Unique Paths II

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
	[0,0,0],
	[0,1,0],
	[0,0,0]
]

The total number of unique paths is 2.
Note: m and n will be at most 100.

解题思路：动态规划

dp[j] = dp[j] + dp[j-1]

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> dp(n ,0);	//初始化都为0

		dp[0] = 1;		//第0行0列的步数

		for (int i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 1)		//边界处理：有一个为1，说明此路不通
				dp[0] = 0;
			for (int j = 1; j < n; ++j)
			{
				//dp[j]为第i行，第j列的步数
				if (obstacleGrid[i][j] == 1)
					dp[j] = 0;
				else
					dp[j] = dp[j] + dp[j - 1];
				cout << i << "," << j << ":" << dp[j] << endl;
			}
		}

		return dp[n - 1];
	}
};

void test()
{
	vector<vector<int>> ob{
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};

	Solution sol;
	cout << sol.uniquePathsWithObstacles(ob) << endl;
}

int main()
{
	test();

	return 0;
}