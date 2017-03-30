/*
leetcode 217. Contains Duplicate
��Ŀ���⣺����һ�����飬�ж��ǲ��ǰ����ظ���Ԫ��
����˼·��������Ȼ�󿴱������ڵ�Ԫ���Ƿ����
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