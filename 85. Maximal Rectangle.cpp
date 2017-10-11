/*
leetcode 85. Maximal Rectangle
题目大意：对于给定的二维矩阵，只有0,1元素，求出最大的子矩阵，该矩阵只
包含1,返回该矩阵的面积。
比如对于如下矩阵：
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
返回6.

解题思路：
以每一行为分割，累积每一列中有多少个连续的1，转化为Largest Rectangle in Histogram。
比如例子中的矩阵，那么在第三层：h3={3,1,3,2,2};此时求最大的矩阵也就是求直方图的最大
矩形的面积。
求Largest Rectangle in Histogram的方法如下：
对于每一个位置i的矩形，其高度为h[i], 我们考虑其向左和向右最大能扩展多少，那么就能求出
当前位置组成的矩形的最大面积。那么就是要找左右刚好比当前h[i]小的值。
使用一个栈，遍历h数组，每遍历一个位置，如果该位置的值i比栈顶对应位置的值大，那么直接入栈，
否则栈顶元素j出栈，新的栈顶为k(为空则为-1)。这说明：j位置的元素，左边刚好比它小的时k位置，
右边刚好比它小的是i位置,因此面积为h[i]*(k-j-1)。
如果最后栈不为空，可以假设有一个高度很小的值，那么所有的都要出栈计算面积。
*/

#include "Header.h"
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		int maxArea = 0;
		vector<int> height(n);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
			}
			maxArea = max(maxArea, GetLargest(height));
		}

		return maxArea;
	}

	int GetLargest(vector<int> h)
	{
		if (h.size() == 0)
			return 0;
		int maxArea = 0;
		stack<int> s;
		for (int i = 0; i < h.size(); ++i)
		{
			while (!s.empty() && h[i] <= h[s.top()])
			{
				int j = s.top();
				s.pop();
				int k = s.empty() ? -1 : s.top();
				int curArea = (i - k - 1) * h[j];
				maxArea = max(maxArea, curArea);
			}
			s.push(i);
		}
		while (!s.empty())
		{
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (h.size() - k - 1)*h[j];
			maxArea = max(curArea, maxArea);
		}

		return maxArea;
	}
};

int main()
{
	vector<vector<char>> v{
		{ '1','0','1','0','0' },
		{ '1','0','1','1','1' },
		{ '1','1','1','1','1' },
		{ '1','0','0','1','0' },
	};

	Solution sol;

	cout << sol.maximalRectangle(v) << endl;
}