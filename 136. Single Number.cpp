/*
leetcode 136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

题目大意：对于给定的数组，里面的整数除了一个以外，其他的都出现两次。找出只出现一次的元素。
解题思路
方法1：把数组的元素放在set中，如果没有就加入，如有有就删除。那么最后set中只剩下一个只出现一次的元素。
方法2：先排序，然后比较。如果一个元素和它前后的元素都不相同，那么这个元素就是只出现一次的元素。
方法3：或操作。进行或运算后，得到的值是只出现一次的元素
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