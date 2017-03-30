/*
leetcode 219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

题目大意：对于给定的数组，判断nums[i] == nums[j]且i与j的距离不大于k
方法1(TLE):直接遍历数组，超时
方法2(使用map):unordered_map<int, int>map，key记录nums[i]，value记录序号i。遍历数组nums，如果找到,由于map[nums[i]]的value是上一次的序号，如果两个序号之差小于等于k那么返回true,否则如果不能找到这个数，则插入(更新)map
方法3(使用set):用一个set维护[i-k-1,i-i]这个范围内的数，这样对于第i个数，如果能在set中找到，那么说明存在，否则继续查找。
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