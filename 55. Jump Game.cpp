/*
leetcode 55. Jump Game

Given an array of non-negative integers, you are initially positioned 
at the first index of the array.
Each element in the array represents your maximum jump length at that 
position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

解题思路：每次应该跳动应该使得当前的位置的数加上该位置下标最大(贪心所在)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int len = nums.size();
		if (len <= 1)
			return true;

		int reach = nums[0];//能够到达最远的地方
		//必须保证reach >= i,否则根本就不能到i的位置
		for (int i = 1; i < len && reach >= i; ++i)
		{
			if (i + nums[i] > reach)
				reach = i + nums[i];
		}

		return (reach >= len-1 ? true : false);
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{ 1,0,2 };
	cout << sol.canJump(nums) << endl;
}

int main()
{
	TEST();

	return 0;
}