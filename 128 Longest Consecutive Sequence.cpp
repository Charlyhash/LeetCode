/*
Leetcode 128. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

题目大意：给定一个数组，找到最长的连续数
解题思路：
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums)
	{
		unordered_set<int> s;
		
		for (int i = 0; i < nums.size(); ++i)
			s.insert(nums[i]);

		int res = 0;
		while (s.size() > 0)
		{
			int tmp = *s.begin();
			s.erase(tmp);

			int count = 1;
			int r = tmp + 1;
			while (s.count(r))
			{
				s.erase(r);
				++r;
				++count;
				
			}

			int l = tmp - 1;
			while (s.count(l))
			{
				s.erase(l);
				--l;
				++count;
				
			}

			res = max(count, res);
		}
		
		return res;
	}
};

void test()
{
	Solution sol;
	vector<int> v{ 100, 4, 200, 1, 3, 2 };
	cout << sol.longestConsecutive(v) << endl;
}

int main()
{
	test();
	return 0;
}