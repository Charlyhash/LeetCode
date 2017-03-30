/*
leetcode 26. Remove Duplicates from Sorted Array
题目大意：对于给定的排序数组，除去多余的数字使得每个数字只出现一次，返回新数组的长度
解题思路：遍历每一个字符，如果这个字符与上一个字符一样的话，就继续，如果不一样，结果加1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
	{
		int ret = 1;
		if (nums.size() == 0)
			return 0;
		for (size_t i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != nums[i - 1])
				nums[ret++] = nums[i];			//要求这些数保存下来
		}

		return ret;
	}
};

void test_removeDuplicates()
{
	vector<int> vInt{1,1,2,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,8,9,9,9,9,9};
	Solution sol;
	cout << sol.removeDuplicates(vInt) << endl;
}

int main()
{
	test_removeDuplicates();
	return 0;
}