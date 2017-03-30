/*
leetcode 81. Search in Rotated Sorted Array II
Search in Rotated Sorted Array : http://blog.csdn.net/charles1e/article/details/51757259
��Ŀ���⣺������Ļ����ϣ������ظ�Ԫ��
����˼·���ο���һƪ�ģ�����������ϣ����nums[mid]==nums[right],��--right,�������Ԫ�ء�
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right)/2;
			if (nums[mid] == target)
				//return mid;
				return true;
			if (nums[mid] < nums[right])
			{
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else if (nums[mid] > nums[right])
			{
				if (target >= nums[left] && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				//����nums[mid]==nums[right]�������ֱ�Ӻ��Լ���
				right--;
			}
		}

		return false;
	}
};

void test_search()
{
	Solution sol;
	vector<int> nums{ 5,6,6,7,7,1,1,1,2,2,3,4 };
	for (int i = 1; i < 10; ++i)
		cout << i << " : " << sol.search(nums, i) << endl;
}

int main()
{
	test_search();

	return 0;
}