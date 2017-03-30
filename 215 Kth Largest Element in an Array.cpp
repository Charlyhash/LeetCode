/*
leetcode 215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

题目大意：查找第k大的数
解题思路：
1. sort,然后找到第n-k+1位置的数
2. 快排：一次排序，排好了一个数，如果刚好是目标位置的数(此处target = nums.size() - k),返回
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		sort(nums.begin(), nums.end());

		return nums[nums.size() - k];
	}

//public :
//	void MyQuickSort(vector<int>& nums, int l, int r)
//	{
//		int pivot = nums[l];
//
//		if (l < r)
//		{
//			int i = l;
//			int j = r;
//			while (i < j)		//一直循环
//			{
//				while (i < j && nums[j] >= pivot)		//从右边扫描，找到第一个<pivot的数
//					j--;
//				if (i < j)
//				{
//					nums[i] = nums[j];		//放到i的位置上
//					++i;					//i向后移动
//				}
//				while (i < j && nums[i] < pivot)	//从左边开始扫描，找到第一个>pivot的数
//					++i;
//				if (i < j)
//				{
//					nums[j] = nums[i];		//放到j的位置上
//					--j;						//j向前移动
//				}
//			}
//			此时i=j,左边比pivot小，右边比pivot大
//			nums[i] = pivot;
//			MyQuickSort(nums, l, i - 1);
//			MyQuickSort(nums, i + 1, r);
//		}
//	}
//
//	int findKthLargest1(vector<int>& nums, int k)
//	{
//		MyQuickSort(nums, 0, nums.size()-1);
//		return nums[nums.size() - k];
//	}

	int Partion(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];

		int i = l;
		int j = r;
		if (l < r)
		{
			while (i < j)		//一直循环
			{
				while (i < j && nums[j] >= pivot)//从右边扫描，找到第一个<pivot的数
					j--;
				if (i < j)
				{
					nums[i] = nums[j];		//放到i的位置上
					++i;					//i向后移动
				}
				while (i < j && nums[i] < pivot)//从左边开始扫描，找到第一个>pivot的数
					++i;
				if (i < j)
				{
					nums[j] = nums[i];		//放到j的位置上
					--j;						//j向前移动
				}
			}
			//此时i=j,左边比pivot小，右边比pivot大
			nums[i] = pivot;	//	确定了第i个元素的位置
			//MyQuickSort(nums, l, i - 1);
			//MyQuickSort(nums, i + 1, r);
		}

		return i;
	}

	int findKthLargest1(vector<int>& nums, int k)
	{
		int target = nums.size() - k;
		int res;
		int l = 0; 
		int r = nums.size() - 1;
		while (l < r)
		{
			res = Partion(nums, l, r);
			if (target > res)
				l = res + 1;
			else if (target < res)
				r = res - 1;
			else
				return nums[res];
		}

		return nums[l];
			
	}
};

void test()
{
	vector<int> nums{ 3,2,1,5,6,4 };
	Solution sol;
	cout << sol.findKthLargest1(nums, 2) << endl;
}

int main()
{
	test();

	return 0;
}