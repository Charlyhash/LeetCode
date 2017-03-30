/*
leetcode 347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

题目大意：对于给定的数组，找到出现次数最多的k个元素
解题思路:
1. 先统计每个元素出现的次数
2. 类似于hashtable,对于每一种次数，都有一个bucket。一个bucket为一个数组，存放出现次数为相同的
元素。然后找出这k个元素即可

20 / 20 test cases passed.
Status: Accepted
Runtime: 36 ms
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//count every element in nums
		unordered_map<int, int> umap;
		for (auto i : nums)
			++umap[i];
		//按照出现的次数放在buckets中
		vector<vector<int>>buckets(nums.size());
		for (auto iter = umap.begin(); iter != umap.end(); ++iter)
		{
			buckets[iter->second - 1].push_back(iter->first);
		}

		vector<int> res;
		//统计最大的k个数
		for (int i = buckets.size() - 1; i >= 0; --i)
		{
			for (int j = 0; j < buckets[i].size(); ++j)
			{
				res.push_back(buckets[i][j]);
				if (res.size() == k)
					return res;
			}
		}
		return res;
	}
};

void test()
{
	Solution sol;
	vector<int> v{ 1,1,1,2,2,3 };
	vector<int> ret =  sol.topKFrequent(v, 2);
	
	for (auto i : ret)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test();

	return 0;
}
