/*
leetcode 62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 3 x 7 grid. How many possible unique paths are there?
Note: m and n will be at most 100.

����˼·����̬�滮
��dp[i][j]��ʾ��(i,j)λ�õĲ�������ô:
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
ע��߽磺��i==0||j==0ʱ��dp[i][j] = 1
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

	//�Ż�����ʡ�ռ�
	int uniquePaths1(int m, int n)
	{
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				dp[j] = dp[j] + dp[j - 1];//��i�е�j�еĲ���֮��
		
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