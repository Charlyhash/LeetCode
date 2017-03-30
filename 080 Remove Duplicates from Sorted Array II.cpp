/*
leetcode 80. Remove Duplicates from Sorted Array II
题目大意：从排序好的数组中删除重复元素，最多允许重复次数为2次
解题思路：对于排序的数组，如果重复次数大于2，那么一定是nums[i] == nums[i-2],即与前两个相等
譬如说：1，1，1，2，2，2，3，4，5。（序号从0开始）第2个和第0个相等，故而说明是重复元素。
在对数组扫描的过程中，要记录数组中删除多余元素后的序号，并将这个序号作为数组的序号，
其他删除的元素直接覆盖就行了。
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search2(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target == nums[mid])
			return mid;

		if (nums[mid] < nums[right])
		{
			if (target > nums[mid] && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			if (nums[left] <= target && nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return -1;
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret = 2;
		if (nums.size() < 2)
			return nums.size();
		for (size_t i = 2; i < nums.size(); ++i)
		{
			if (nums[i] != nums[ret - 2])		//判断重复的次数是不是大于2
				nums[ret++] = nums[i];			//直接覆盖，用ret记录新的位置
		}

		return ret;
	}
};

void test_removeDuplicates()
{
	Solution sol;
	vector<int> nums{ 1,1,1,2,2,2,2,2,3,3,4,5,6,6,6,7,7,8,9,10 };
	int ret = sol.removeDuplicates(nums);
	cout << ret << endl;
	for (int i = 0; i < ret; ++i)
		cout << nums[i] << " ";
	cout << endl;
}

int main()
{
	test_removeDuplicates();

	return 0;
}