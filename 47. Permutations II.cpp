/*
leetcode 47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
	[1,1,2],
	[1,2,1],
	[2,1,1]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		vector<vector<int>> ret;
		if (nums.size() == 0)
			return ret;

		vector<int> visited;
		vector<bool> isVisited(nums.size(), false);//���nums[i]�Ƿ���ʹ�������
		sort(nums.begin(), nums.end());//�����������ͺܷ��㿴�ǲ����Ѿ�ʹ�����Ԫ��������

		DFS(ret, visited, isVisited,nums);

		return ret;
	}

	void DFS(vector<vector<int>>& ret, vector<int>& visited, vector<bool> isVisited, vector<int>& nums)
	{
		if (visited.size() == nums.size())
		{
			ret.push_back(visited);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			//�ظ�Ԫ�غ���
			//ֻҪǰһ��Ԫ��û�з��ʹ����Һ�ǰһ��Ԫ����ȣ�˵��������
			//ǰһ��Ԫ��ʱ�Ѿ������������
			if (i > 0 && !isVisited[i-1] && nums[i] == nums[i-1])
				continue;
			if (!isVisited[i])
			{
				visited.push_back(nums[i]);
				isVisited[i] = true;
				DFS(ret, visited,isVisited, nums);
				visited.pop_back();
				isVisited[i] = false;
			}
		}

	}
};

void TEST()
{
	Solution sol;
	vector<int> v{ 1,1,2 };
	vector<vector<int>> ret = sol.permuteUnique(v);

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