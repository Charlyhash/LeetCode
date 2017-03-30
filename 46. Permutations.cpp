/*
leetcode 46. Permutations
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
	[1,2,3],
	[1,3,2],
	[2,1,3],
	[2,3,1],
	[3,1,2],
	[3,2,1]
]

����˼·������

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> ret;
		if (nums.size() == 0)
			return ret;
		vector<int> visited;
		DFS(ret, visited, nums);

		return ret;
	}

	//visited��ŵ��Ǽ���������
	void DFS(vector<vector<int>>& ret, vector<int>& visited, vector<int>& nums)
	{
		if (nums.size() == visited.size())
		{
			ret.push_back(visited);
			return;
		}
		//ÿһ�ζ�����һ��nums[i]�е���
		for (int i = 0; i < nums.size(); ++i)
		{
			auto isVisited = find(visited.begin(), visited.end(), nums[i]);
			if (isVisited == visited.end())//nums[i]û�з��ʹ�
			{
				visited.push_back(nums[i]);
				DFS(ret, visited, nums);
				visited.pop_back();
			}
		}
	}
};

void TEST()
{
	Solution sol;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> ret = sol.permute(nums);

	for (auto v : ret)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}

int main()
{
	TEST();

	return 0;
}