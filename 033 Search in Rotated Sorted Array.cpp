/*
leetcode 33. Search in Rotated Sorted Array
reference:http://blog.csdn.net/ljiabin/article/details/40453607
��Ŀ���⣺һ������������ĳ����ѡ���ˣ��������ת�����������ָ����Ԫ��target
�ҵ��ͷ����������е���ţ����򷵻�-1
����˼·��
1����Ȼ�ǿ���ֱ���ѵģ����Ӷ�O(n)����Ҳ���Թ�.���Ƕ�����һ��˳������飬Ӧ��
�и���Ч�ķ�����
2�����ֲ��ң����Ӷ�O��logn����:���ֲ���ʱҪע��ת�۵㡣��ʵֻ��Ҫһ������Ϳ��ԡ�
��Ϊ3�����
(1) δ��ת����1��2��3��4��5��6. ������nums[left] < nums[right]
(2) ��ת��λ�ó������е㣬��3��4��5��6��1��2��������nums[left]>nums[mid]
(3) ��תλ�ò������м�㣬��5��6��1��2��3��4�����������������������һ���ˡ�
���£�3��(1)��(2)���Ժϲ���д��~�����������������ֱ�����һ���ж�
I) nums[mid] < nums[right],˵��mid��rightΪ����ģ��ж�target�Ƿ���mid��right֮��,
������ڣ���ôһ����left��mid֮��
II)nums[mid] >= nums[right],˵��left��mid������ģ��ж�target�Ƿ���left��mid֮�䣬
������ڣ���ôһ����left��mid֮��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//����ÿ�������
	int search(vector<int>& nums, int target) 
	{
		int len = nums.size();
		if (len == 0)
			return -1;
		return binarySearch(nums, 0, len - 1, target);
	}
	//1����ÿһ��������з�����˼·�ܺ�
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

	//2��������д�������������õݹ��ܶడ��
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

	//3����2�еĺ�����д�����ˡ���Ϊֻ��Ҫ���ּ���
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