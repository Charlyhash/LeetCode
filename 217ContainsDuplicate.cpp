/*
leetcode 217. Contains Duplicate
题目大意：对于一个数组，判断是不是包含重复的元素
解题思路：先排序，然后看遍历相邻的元素是否相等
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		for (size_t i = 1; i < nums.size(); ++i)
			if (nums[i] == nums[i - 1])
				return true;
		return false;
	}
};

void test_containsDuplicate()
{
	Solution sol;
	vector<int> nums{3, 4, 5, 6,1,2,7,8,10,9};
	vector<int> nums2{ 1, 2, 3, 9,7,6,5,4,1 };
	cout << "nums: " << sol.containsDuplicate(nums) << endl;
	cout << "nums2: " << sol.containsDuplicate(nums2) << endl;
}

int main()
{
	test_containsDuplicate();

	return 0;
}