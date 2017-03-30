/*
leetcode 15. 3Sum

Given an array S of n integers, are there elements a, b, c 
in S such that a + b + c = 0? Find all unique triplets 
in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
Subscribe to see which companies asked this question

��Ŀ���⣺�Ӹ����������ҵ�3�����ĺ�Ϊ0
����˼·���̶�һ������תΪ2Sum
1.�ȶ���������
2.ɨ�����飬����ÿһ�������൱�����������2Sum��targetΪ0-nums[i]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int i = 0; i < len - 2; ++i)
		{
			//�������ظ���Ԫ��
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int target1 = 0 - nums[i];
			twoSum(nums, i + 1, target1, ret);
		}

		return ret;
	}

	//ת��Ϊ2Sum����ʼλ��Ϊstart,��Ӧ��Ϊtarger
	//����Ϊnums,�ѽ�������ret�С�
	void twoSum(vector<int>& nums, int start, int target, vector<vector<int>>& ret)
	{
		int low = start;
		int high = nums.size() - 1;
		//�ҵ���Ϊtarget������������Ϊ���Ѿ��ź�������飬����ֱ�Ӵ�ǰ��ͺ�����ӿ�ʼ���ҡ�
		//Ҫ�ҵ����к�Ϊtarget������������ɡ�
		while (low < high)
		{
			int tmp = nums[low] + nums[high];
			if (tmp < target)
				++low;
			else if (tmp > target)
				--high;
			else
			{
				ret.push_back(vector<int>{nums[start - 1], nums[low], nums[high]});

				//�����ظ�
				int k = low + 1;
				while(k < high && nums[k] == nums[low])
					++k;
				low = k;
				k = high - 1;
				while (k > low && nums[k] == nums[high])
					k--;
				high = k;
			}
		}
	}
};

void test()
{
	vector<int> v{ -1, 0, 1, 2, -1, -4 };
	Solution sol;
	vector<vector<int>> ret = sol.threeSum(v);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

}

int main()
{
	test();

	return 0;
}