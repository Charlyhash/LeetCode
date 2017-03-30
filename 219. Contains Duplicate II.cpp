/*
leetcode 219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

��Ŀ���⣺���ڸ��������飬�ж�nums[i] == nums[j]��i��j�ľ��벻����k
����1(TLE):ֱ�ӱ������飬��ʱ
����2(ʹ��map):unordered_map<int, int>map��key��¼nums[i]��value��¼���i����������nums������ҵ�,����map[nums[i]]��value����һ�ε���ţ�����������֮��С�ڵ���k��ô����true,������������ҵ�������������(����)map
����3(ʹ��set):��һ��setά��[i-k-1,i-i]�����Χ�ڵ������������ڵ�i�������������set���ҵ�����ô˵�����ڣ�����������ҡ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	//TLE
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0)
			return false;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				if (i+j >= len)
					break;
				if (nums[i] == nums[i + j])
					return true;
			}
		}

		return false;
	}

	bool containsNearbyDuplicate1(vector<int>& nums, int k)
	{
		unordered_map<int, int>map;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
				return true;
			else
				map[nums[i]] = i;
		}

		return false;
	}

	bool containsNearbyDuplicate2(vector<int>& nums, int k)
	{
		unordered_set<int> s;

		if (k <= 0)
			return false;
		if (k >= nums.size())
			k = nums.size() - 1;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > k)
				s.erase(nums[i-k-1]);
			if (s.find(nums[i]) != s.end())
				return true;
			s.insert(nums[i]);
		}

		return false;
	}
};

void test()
{
	vector<int> v{ 1,2,3,1,4,5,0,3 };
	Solution sol;
	cout << sol.containsNearbyDuplicate1(v, 2) << endl;
	cout << sol.containsNearbyDuplicate1(v, 3) << endl;
	cout << sol.containsNearbyDuplicate2(v, 4) << endl;
	cout << sol.containsNearbyDuplicate2(v, 5) << endl;
}

int main()
{
	test();

	return 0;
}