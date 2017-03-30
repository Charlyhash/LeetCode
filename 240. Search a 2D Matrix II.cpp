/*
leetcode 240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
	[1,   4,  7, 11, 15],
	[2,   5,  8, 12, 19],
	[3,   6,  9, 16, 22],
	[10, 13, 14, 17, 24],
	[18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.

题目大意：从给定的二维数组中判断一个数是不是存在。该二维数组每行都是排序的元素，每一列也是排序的元素
解题思路：
从右上角开始搜索，如果该位置的值比target大,cols--;如果该位置的值比target小,row++。直到cols或rows超出边界。O(m+n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		if (matrix.data() == nullptr)
			return false;
		int rows = matrix.size();
		int cols = matrix[0].size();

		int i = 0, j = cols-1;
		while (i >= 0 && i < rows && j >= 0 && j <= cols - 1)
		{
			int cur = matrix[i][j];
			if (cur == target)
				return true;
			else if (cur < target)
				++i;
			else
				--j;
		}

		return false;
	}
};

void test()
{
	vector<vector<int>>m{
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}
	};
	Solution sol;
	cout << sol.searchMatrix(m, 5) << endl;
	cout << sol.searchMatrix(m, 20) << endl;
	cout << sol.searchMatrix(m, 18) << endl;

	vector<vector<int>> m1;
	cout << sol.searchMatrix(m1, 0) << endl;
}

int main()
{
	test();

	return 0;
}