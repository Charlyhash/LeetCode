/*
leetcode 300. Longest Increasing Subsequence
IMC解法
基本思路：
对于数组nums[] = [10, 9, 2, 5, 3, 7, 101, 18],求LIS
维护一个数组D[],D[1]=nums[0],此时LIS中有一个元素10，长度len=1。
对于后面的数，设当前LIS长度为len:
1. nums[i] > D[len],更新D[],len++,D[len] = nums[i]
2. 否则在D[1...len]中找到一个最大的j,满足D[j]<A[i],那么D[j] < nums[i] <= D[j+1].D[j+1]=nums[i]
此时的D[]为更有潜力的LIS。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;
		vector<int> d(nums.size(), 0);
		int top = 0;		//最后一个元素下标
		d[0] = nums[0];
		for (size_t i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > d[top])
			{
				++top;
				d[top] = nums[i];
			}
			else
			{
				int pos = MyLowerBound(d, top + 1, nums[i]);
				d[pos] = nums[i];
			}
		}

		return top+1;
	}
	
	int MyLowerBound(vector<int> &v, int size, int key)
	{
		int left = 0;
		int right = size - 1;
		int mid;
		int pos = 0;//记录第一个>=key的元素位置
		while (left < right)
		{
			mid = (left + right) / 2;
			if (v[mid] < key)    //v[mid]<key,在右边查找
			{
				left = mid + 1;
				pos = left;
			}
			else
			{
				right = mid;    //在左边查找，因为mid可以能就是要找的位置，因此不是mid-1
				pos = right;
			}
		}

		return pos;
	}

};

void TEST_LIS()
{
	Solution sol;
	vector<int> v{ 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << sol.lengthOfLIS(v) << endl;
}


int main()
{
	TEST_LIS();

	return 0;
}