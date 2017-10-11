/*
leetcode:

题目大意：
来源：牛客网
有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口
每次向右边滑一个位置。
例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时：
[4 3 5] 4 3 3 6 7 窗口中最大值为5
4 [3 5 4] 3 3 6 7 窗口中最大值为5
4 3 [5 4 3] 3 6 7 窗口中最大值为5
4 3 5 [4 3 3] 6 7 窗口中最大值为4
4 3 5 4 [3 3 6] 7 窗口中最大值为6
4 3 5 4 3 [3 6 7] 窗口中最大值为7

如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。请实现一个函数，
给定一个数组arr，窗口大小w。返回一个长度为n-w+1的数组res,res[i]表示每一种
窗口状态下的最大值。以本题为例，结果应该返回[5,5,5,4,6,7]。

解题思路：
1.直接暴力计算每k组数中的最大值，时间复杂度为O(NK)
2.维护一个双端队列，队列里面保存的时当前位置之前的最大值的下标，当前下标如果过期
则弹出(=i-k).

*/

#include "Header.h"

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{
		vector<int> ret;
		if (nums.size() == 0)
			return ret;
		deque<int> qmax; //记录当前最大值的位置
		for (int i = 0; i < nums.size(); ++i)
		{
			while (!qmax.empty() && nums[qmax.back()] < nums[i])
				qmax.pop_back();
			qmax.push_back(i);
			if (qmax.front() == i - k) //判断是否过期
				qmax.pop_front();
			if (i >= k - 1)
				ret.push_back(nums[qmax.front()]);
		}

		return ret;
	}

	//枚举
	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		vector<int> ret;
		if (nums.size() == 0)
			return ret;
		for (int i = 0; i <= nums.size() - k; ++i)
		{
			int tmp = nums[i];
			for (int j = 1; j < k; ++j)
				tmp = max(tmp, nums[i + j]);
			ret.push_back(tmp);
		}

		return ret;
	}
};

int main()
{
	vector<int> v{ 1,3,-1,-3,5,3,6,7 };
	Solution sol;
	vector<int> ret = sol.maxSlidingWindow(v, 3);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	return 0;
}