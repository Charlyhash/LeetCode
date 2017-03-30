/*
 * leetcode 064. Minimum Path Sum
 * dp问题 dp(i,j) = min(dp(i,j-1), dp(i-1,j))
 *解决思路：用一个二维数组记录从起点到每一个点的最短路径。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> result(grid);
		//对于边界，单独计算
		for (int i = 1; i < row; ++i)
			result[i][0] += result[i - 1][0];
		for (int j = 1; j < col; ++j)
			result[0][j] += result[0][j-1];

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				result[i][j] += min(result[i - 1][j], result[i][j - 1]);
			}
		}
        //row-1,col-1即为要求的最短路径
		return result[row - 1][col - 1];
	}
};


void TEST_SOLUTION()
{
	Solution sol;
	vector<vector<int>> grid{
		{5,1,2,3,6},
		{7, 8, 5, 3, 2},
		{1,3,5,8,2},
		{4,3,2,6,5} };

	cout << sol.minPathSum(grid) << endl;
}

int main()
{
	TEST_SOLUTION();

	return 0;
}
