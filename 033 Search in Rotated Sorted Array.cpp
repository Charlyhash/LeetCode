/*
leetcode 33. Search in Rotated Sorted Array
reference:http://blog.csdn.net/ljiabin/article/details/40453607
题目大意：一个排序数组绕某个数选择了，在这个旋转后的数组中找指定的元素target
找到就返回在数组中的序号，否则返回-1
解题思路：
1、当然是可以直接搜的（复杂度O(n)），也可以过.但是对于有一定顺序的数组，应该
有更高效的方法。
2、二分查找（复杂度O（logn））:二分查找时要注意转折点。其实只需要一边有序就可以。
分为3种情况
(1) 未旋转，如1，2，3，4，5，6. 条件是nums[left] < nums[right]
(2) 旋转的位置超过了中点，如3，4，5，6，1，2。条件是nums[left]>nums[mid]
(3) 旋转位置不超过中间点，如5，6，1，2，3，4。除了上面两种情况就是这一种了。
更新：3、(1)和(2)可以合并了写啊~这样两种情况，可以直接完成一次判断
I) nums[mid] < nums[right],说明mid到right为有序的，判断target是否在mid和right之间,
如果不在，那么一定在left和mid之间
II)nums[mid] >= nums[right],说明left到mid是有序的，判断target是否在left到mid之间，
如果不在，那么一定在left和mid之间
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//考虑每种情况的
	int search(vector<int>& nums, int target) 
	{
		int len = nums.size();
		if (len == 0)
			return -1;
		return binarySearch(nums, 0, len - 1, target);
	}
	//1、对每一种情况进行分析，思路很好
	int binarySearch(vector<int>& nums, int left, int right, int target)
	{
		if (left > right)
			return -1;
		int mid = (left + right) / 2;
		if (nums[left] == target)
			return left;
		if (nums[mid] == target)
			return mid;
		if (nums[right] == target)
			return right;
		//(1)
		if (nums[left] <= nums[right])
		{
			if (target < nums[left] || target > nums[right])
				return -1;
			if (target < nums[mid] && target > nums[left])
				return binarySearch(nums, left + 1, mid - 1, target);
			else
				return binarySearch(nums, mid + 1, right - 1, target);
		}
		//(2)
		else if (nums[left] < nums[mid])
		{
			if (target > nums[left] && target < nums[mid])
				return binarySearch(nums, left + 1, mid - 1, target);
			else
				return binarySearch(nums, mid + 1, right - 1, target);
		}
		else //(3)
		{
			if (target > nums[mid] && target < nums[right])
				return binarySearch(nums, mid + 1, right - 1, target);
			else
				return binarySearch(nums, left + 1, mid - 1, target);
		}
	}

	//2、合起来写就是这样，不用递归快很多啊！
	int search2(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right)/2;
			if (target == nums[mid])
				return mid;
			if (nums[left] <= nums[right]) //(1)
			{
				if (target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else if (nums[left] <= nums[mid]) //(2)
			{
				if (target > nums[mid] || target < nums[left])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
			{
				if (target < nums[mid] || target > nums[right])
					right = mid - 1;
				else
					left = mid + 1;
			}
		}

		return -1;
	}

	//3、把2中的合起来写就行了。因为只需要两种即可
	int search3(vector<int>& nums, int target)
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
};

void test_search()
{
	Solution sol;
	vector<int> nums1{278,280,281,286,287,290,2,3,4,8,9,14,15,16,21,24,25,31,32,34,36,37,42,45,51,52,54,55,60,63,66,68,69,71,76,81 };
	vector<int> nums2{ 7,8,1,2,3,4,5,6 };
	vector<int> nums3{ 3,4,5,6,7,8,1,2 };
	vector<int> nums{1};

	cout << sol.search(nums, 2) << endl;
	cout << sol.search(nums1, 286) << endl;
	cout << sol.search(nums2, 5) << endl;
	cout << sol.search(nums3, 5) << endl;

	cout << sol.search2(nums, 2) << endl;
	cout << sol.search2(nums1, 286) << endl;
	cout << sol.search2(nums2, 5) << endl;
	cout << sol.search2(nums3, 5) << endl;

	cout << sol.search3(nums, 2) << endl;
	cout << sol.search3(nums1, 286) << endl;
	cout << sol.search3(nums2, 5) << endl;
	cout << sol.search3(nums3, 5) << endl;
}


int main()
{
	test_search();
	return 0;
}