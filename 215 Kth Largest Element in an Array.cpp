/*
leetcode 215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 �� k �� array's length.

��Ŀ���⣺���ҵ�k�����
����˼·��
1. sort,Ȼ���ҵ���n-k+1λ�õ���
2. ���ţ�һ�������ź���һ����������պ���Ŀ��λ�õ���(�˴�target = nums.size() - k),����
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
//			while (i < j)		//һֱѭ��
//			{
//				while (i < j && nums[j] >= pivot)		//���ұ�ɨ�裬�ҵ���һ��<pivot����
//					j--;
//				if (i < j)
//				{
//					nums[i] = nums[j];		//�ŵ�i��λ����
//					++i;					//i����ƶ�
//				}
//				while (i < j && nums[i] < pivot)	//����߿�ʼɨ�裬�ҵ���һ��>pivot����
//					++i;
//				if (i < j)
//				{
//					nums[j] = nums[i];		//�ŵ�j��λ����
//					--j;						//j��ǰ�ƶ�
//				}
//			}
//			��ʱi=j,��߱�pivotС���ұ߱�pivot��
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
			while (i < j)		//һֱѭ��
			{
				while (i < j && nums[j] >= pivot)//���ұ�ɨ�裬�ҵ���һ��<pivot����
					j--;
				if (i < j)
				{
					nums[i] = nums[j];		//�ŵ�i��λ����
					++i;					//i����ƶ�
				}
				while (i < j && nums[i] < pivot)//����߿�ʼɨ�裬�ҵ���һ��>pivot����
					++i;
				if (i < j)
				{
					nums[j] = nums[i];		//�ŵ�j��λ����
					--j;						//j��ǰ�ƶ�
				}
			}
			//��ʱi=j,��߱�pivotС���ұ߱�pivot��
			nums[i] = pivot;	//	ȷ���˵�i��Ԫ�ص�λ��
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