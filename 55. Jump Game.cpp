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

����˼·��ÿ��Ӧ������Ӧ��ʹ�õ�ǰ��λ�õ������ϸ�λ���±����(̰������)
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

		int reach = nums[0];//�ܹ�������Զ�ĵط�
		//���뱣֤reach >= i,��������Ͳ��ܵ�i��λ��
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