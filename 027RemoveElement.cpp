/*
leetcode 27. Remove Element
题目大意：删除数组中给定的数组，返回新数组的长度len,并且前len个数字为新的数组的内容
譬如说：nums = [3,2,2,3], val = 3， returned length = 2, with the first two elements of nums being 2.
解题思路：扫描每一个数字，并用原来的数组保存不同的数。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int ret = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != val)
			{
				nums[ret++] = nums[i];
			}
		}
		return ret;
	}
};

void test_removeElement()
{
	Solution sol;
	vector<int> nums{ 1,2,3,4,1,2,3,4,5,1,2,3};
	int val = 2;
	size_t len = sol.removeElement(nums, val);
	cout << len << endl;
	for (size_t i = 0; i < len; ++i)
		cout << nums[i] << " ";
	cout << endl;
}

int main()
{
	test_removeElement();

	return 0;
}