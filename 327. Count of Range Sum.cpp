/*
leetcode 327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

题目大意：对于给定的数组和上下界，求有多少个不同的区间使得每个区间和载给定的上下限之间
解题思路：
1.暴力：先求和，然后枚举
2.使用multiset,可以很方便求出满足条件元素个数
3.归并排序。第一步还是求和sum[i+1]=sum[i]+nums[i]，然后[i,j]的和可以用sum[j]-sum[i]来表示。
这里需要用归并排序，使得左右取件的sum有序。（为什么可以这样做，不是区间统计吗？因为这里只需要统
计个数，而不是具体的范围）。枚举左区间的坐标i，找到右区间满足：
第一个sum[rl]-sum[i]>=lower的临界值rl;第一个sum[rr]-sum[i]<upper的临界值rr.则贡献的个数为
rr-rl个。而对于排序的数组，合并的复杂度为O(n).每次计算完后进行归并排序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
	//朴素求法：先求和，然后枚举
	/*int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.size() == 0)
			return 0;
		vector<int> sums(nums.size()+1,0);
		for (int i = 0; i < nums.size(); ++i)
			sums[i + 1] = sums[i] + nums[i];
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j <= nums.size(); ++j)
			{
				if (lower <= sums[j] - sums[i] && sums[j] - sums[i] <= upper)
					ans++;
			}
		}

		return ans;
	}*/

	int countRangeSum1(vector<int>& nums, int lower, int upper) {
		multiset<long long> pSum;
		int res = 0, i;
		long long sum = 0;
		for (i = 0, pSum.insert(0); i < nums.size(); ++i)
		{
			sum += nums[i];
			//直接计算
			res += distance(pSum.lower_bound(sum - upper), pSum.upper_bound(sum - lower));
			pSum.insert(sum);
		}

		return res;
	}

	int countRangeSum(vector<int>& nums, int lower, int upper)
	{
		int len = nums.size();

		vector<long> sums(len + 1, 0);
		for (int i = 0; i < len; ++i)
		{
			sums[i + 1] = sums[i] + nums[i];
		}

		return MergeSort(sums, 1, len, lower, upper);

	}

	int MergeSort(vector<long>&sums, int left, int right, int lower, int upper)
	{
		int mid, i, r, res, j, k,t;
		if (left > right)
			return 0;
		if (left == right)
			return (((sums[left] >= lower) && (sums[left] <= upper)) ? 1 : 0);
		
		vector<long long> tmp(right - left + 1, 0);//辅助空间，用于归并排序
		mid = (left + right) / 2;
		//首先计算非重叠的部分
		res = MergeSort(sums, left, mid, lower, upper) + MergeSort(sums, mid + 1, right, lower, upper);
		//计算边界符合要求的个数
		r = 0; t = mid + 1;
		for (i = left, j = k = mid + 1; i <= mid; ++i)
		{
			//对于第i个数
			//1。先找到第一个j，满足sums[j] - sums[i] < lower
			while (j <= right && sums[j] - sums[i] < lower) ++j;
			//2. 在找到第一个k满足sums[k] - sums[i] <= upper
			while (k <= right && sums[k] - sums[i] <= upper) ++k;
			//3.这样在边界的地方就会有k-j个
			res += k - j;
			//4. 把右边部分比sums[i]小的数和sums[i]放入缓存数组中,为了以后的排序
			while (t <= right && sums[t] < sums[i])
				tmp[r++] = sums[t++];
			tmp[r++] = sums[i];
		}
		//现在tmp里面是排好序的，复制过去，那么从left到right就是已经排好序的了
		for (i = 0; i < r; ++i)
			sums[left + i] = tmp[i];

		return res;
	
	} 
};

void TEST()
{
	Solution sol;
	vector<int>nums{ -2,5,-1 };
	int ret = sol.countRangeSum(nums, -2, 2);
	cout << ret << endl;
}

int main()
{
	TEST();

	return 0;
}
