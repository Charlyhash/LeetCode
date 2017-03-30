/*
leetcode 304. Range Sum Query 2D - Immutable 
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5

The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
1. You may assume that the matrix does not change.
2. There are many calls to sumRegion function.
3. You may assume that row1 ≤ row2 and col1 ≤ col2.

题目大意：求和
解题思路：DP,求解 dp[i][j]等于从坐标matrix[0][0]到matrix[i - 1][j - 1]中所有元素的和
*/

#include <iostream>
#include <vector>

using namespace std;

void PVec(vector<vector<int>> &matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "------------------" << endl;
}

class NumMatrix {
public:
	vector<vector<int>> dp;
	NumMatrix(vector<vector<int>> &matrix) 
	{
		if (matrix.empty())
			return;
		int row = matrix.size();
		int col = matrix[0].size();
		dp.resize(row+1, vector<int>(col+1, 0));
		PVec(dp);
		for (int i = 1; i < dp.size(); ++i)
		{
			for (int j = 1; j < dp[0].size(); ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i-1][j-1];
				PVec(dp);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) 
	{
			return dp[row2+1][col2+1]+dp[row1][col1]- dp[row1][col2+1] - dp[row2+1][col1];
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


void test1()
{
	vector<vector<int>> m{
		{ 3, 0, 1, 4, 2 },
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{ 4, 1, 0, 1, 7 },
		{ 1, 0, 3, 0, 5 }
	};
	NumMatrix numMatrix(m);
	
	cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
	
}

void test2()
{
	vector<vector<int>> m{
		{-4, -5 }
	};
	NumMatrix n(m);
		
	cout << n.sumRegion(0, 0, 0, 0) << endl;
	cout << n.sumRegion(0, 0, 0, 1) << endl;
	cout << n.sumRegion(0, 1, 0, 1) << endl;
}

int main()
{
	test2();
	return 0;
}