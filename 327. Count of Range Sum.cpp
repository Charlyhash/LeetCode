/*
leetcode 327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i �� j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

��Ŀ���⣺���ڸ�������������½磬���ж��ٸ���ͬ������ʹ��ÿ��������ظ�����������֮��
����˼·��
1.����������ͣ�Ȼ��ö��
2.ʹ��multiset,���Ժܷ��������������Ԫ�ظ���
3.�鲢���򡣵�һ���������sum[i+1]=sum[i]+nums[i]��Ȼ��[i,j]�ĺͿ�����sum[j]-sum[i]����ʾ��
������Ҫ�ù鲢����ʹ������ȡ����sum���򡣣�Ϊʲô��������������������ͳ������Ϊ����ֻ��Ҫͳ
�Ƹ����������Ǿ���ķ�Χ����ö�������������i���ҵ����������㣺
��һ��sum[rl]-sum[i]>=lower���ٽ�ֵrl;��һ��sum[rr]-sum[i]<upper���ٽ�ֵrr.���׵ĸ���Ϊ
rr-rl������������������飬�ϲ��ĸ��Ӷ�ΪO(n).ÿ�μ��������й鲢����
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
	//�����󷨣�����ͣ�Ȼ��ö��
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
			//ֱ�Ӽ���
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
		
		vector<long long> tmp(right - left + 1, 0);//�����ռ䣬���ڹ鲢����
		mid = (left + right) / 2;
		//���ȼ�����ص��Ĳ���
		res = MergeSort(sums, left, mid, lower, upper) + MergeSort(sums, mid + 1, right, lower, upper);
		//����߽����Ҫ��ĸ���
		r = 0; t = mid + 1;
		for (i = left, j = k = mid + 1; i <= mid; ++i)
		{
			//���ڵ�i����
			//1�����ҵ���һ��j������sums[j] - sums[i] < lower
			while (j <= right && sums[j] - sums[i] < lower) ++j;
			//2. ���ҵ���һ��k����sums[k] - sums[i] <= upper
			while (k <= right && sums[k] - sums[i] <= upper) ++k;
			//3.�����ڱ߽�ĵط��ͻ���k-j��
			res += k - j;
			//4. ���ұ߲��ֱ�sums[i]С������sums[i]���뻺��������,Ϊ���Ժ������
			while (t <= right && sums[t] < sums[i])
				tmp[r++] = sums[t++];
			tmp[r++] = sums[i];
		}
		//����tmp�������ź���ģ����ƹ�ȥ����ô��left��right�����Ѿ��ź������
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
