/*
leetcode 90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		int len = nums.size();
		if (len == 0)
			return ret;
		//�Ƿ��Ѿ�ʹ�ù���
		vector<bool> used(len, false);
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		DFS(ret, used, nums, tmp, 0);

		return ret;

	}

	void DFS(vector<vector<int>>& ret, vector<bool>& used, vector<int>& nums, vector<int>& tmp, int count)
	{
		if (count >= nums.size())
		{
			ret.push_back(tmp);
			return;
		}

		//not use nums[count]
		DFS(ret, used, nums, tmp, count + 1);
		//�����ظ������ǵ�һ��Ԫ�أ����߸�Ԫ�ز�����ǰһ��Ԫ�ػ��߸�Ԫ�ص���ǰһ��Ԫ�ص���ǰһ��Ԫ���Ѿ�ʹ�ù�
		if (!count || nums[count] != nums[count - 1] || (nums[count] == nums[count - 1] && used[count - 1]))
		{
			used[count] = true;
			tmp.push_back(nums[count]);
			DFS(ret, used, nums, tmp, count+1);
			tmp.pop_back();
			used[count] = false;
		}
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{1,2,2};
	vector<vector<int>> ret = sol.subsetsWithDup(nums);

	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

}

int main()
{
	TEST();

	return 0;
}