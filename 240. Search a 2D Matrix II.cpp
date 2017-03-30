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

��Ŀ���⣺�Ӹ����Ķ�ά�������ж�һ�����ǲ��Ǵ��ڡ��ö�ά����ÿ�ж��������Ԫ�أ�ÿһ��Ҳ�������Ԫ��
����˼·��
�����Ͻǿ�ʼ�����������λ�õ�ֵ��target��,cols--;�����λ�õ�ֵ��targetС,row++��ֱ��cols��rows�����߽硣O(m+n)
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