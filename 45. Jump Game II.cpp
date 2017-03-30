/*
leetcode 45. Jump Game II

Given an array of non-negative integers, you are initially positioned 
at the first index of the array.
Each element in the array represents your maximum jump length at that
position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step
from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

解题思路：
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int jump(vector<int>& nums) 
	{
		int res = 0;
		int len = nums.size();
		if (len <= 1)
			return 0;

		int steps = 0;		//步数
		int index = 0;		//临时下标
		int reach = nums[0];//当前能到的最大长度
		
		while (reach < len - 1)//没有到len-1
		{
			++steps;		//加1步
			int nxt = reach;//能够到达的最远地方
			//从index到reach找到一个能走到最远的点
			while (index < len && index <= reach)
			{
				nxt = max(nxt, index + nums[index]);	//能到的最远距离
				++index;								//保存的下标
			}
			if (nxt <= reach)	//这说明该位置是0，没法走下去了
				return -1;
			reach = nxt;
		}

		return steps + 1;
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{ 2,3,1,1,4 };
	cout << sol.jump(nums) << endl;
}

int main()
{
	TEST();

	return 0;
}