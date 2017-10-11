/*
leetcode 84. Largest Rectangle in Histogram
题目大意：
对于给定的n个非负整数，代表直方图的高度，宽度为1，在直方图中找出最大面积的矩形

解题思路：
需要找到每个矩形左右能最大扩展到多少，即找到左右刚好比当前高度小的位置，用栈来实现
使用一个栈，遍历h数组，每遍历一个位置，如果该位置的值i比栈顶对应位置的值大，那么直接入栈，
否则栈顶元素j出栈，新的栈顶为k(为空则为-1)。这说明：j位置的元素，左边刚好比它小的时k位置，
右边刚好比它小的是i位置,因此面积为h[i]*(k-j-1)。
如果最后栈不为空，可以假设有一个高度很小的值，那么所有的都要出栈计算面积。
*/
#include "Header.h"

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) 
	{
		int n = heights.size();
		if (n == 0)
			return 0;

		stack<int> s;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			while (!s.empty() && heights[i] <= heights[s.top()])
			{
				int j = s.top();
				s.pop();
				int k = s.empty() ? -1 : s.top();
				int curArea = (i - k - 1)* heights[j];
				ret = max(ret, curArea);
			}
			s.push(i);
		}
		while (!s.empty())
		{
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (n - k - 1)* heights[j];
			ret = max(ret, curArea);
		}

		return ret;
	}
};

int main()
{

	vector<int> v{2,1,5,6,2,3};
	Solution sol;
	cout << sol.largestRectangleArea(v) << endl;

	return 0;
}
