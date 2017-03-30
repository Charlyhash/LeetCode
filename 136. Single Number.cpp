/*
leetcode 136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

��Ŀ���⣺���ڸ��������飬�������������һ�����⣬�����Ķ��������Ρ��ҳ�ֻ����һ�ε�Ԫ�ء�
����˼·
����1���������Ԫ�ط���set�У����û�оͼ��룬�����о�ɾ������ô���set��ֻʣ��һ��ֻ����һ�ε�Ԫ�ء�
����2��������Ȼ��Ƚϡ����һ��Ԫ�غ���ǰ���Ԫ�ض�����ͬ����ô���Ԫ�ؾ���ֻ����һ�ε�Ԫ�ء�
����3������������л�����󣬵õ���ֵ��ֻ����һ�ε�Ԫ��
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		unordered_set<int> s;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (s.find(nums[i]) == s.end())
				s.insert(nums[i]);
			else
				s.erase(nums[i]);
		}

		return *s.begin();
	}

	int singleNumber1(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		if (nums[0] != nums[1])
			return nums[0];
		for (int i = 1; i < nums.size() - 1; ++i)
		{
			if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
				return nums[i];
		}

		return nums[nums.size() - 1];
	}

	int singleNumber2(vector<int>& nums)
	{
		int ret = nums[0];
		int len = nums.size();
		for (auto i = 1; i < len ; ++i)
			ret ^= nums[i];

		return ret;
	}
};

void test()
{
	Solution sol;
	vector<int> nums{2,2,1};
	int ret = sol.singleNumber2(nums);
	cout << ret << endl;
}

int main()
{
	test();

	return 0;
}