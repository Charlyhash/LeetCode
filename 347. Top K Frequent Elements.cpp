/*
leetcode 347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 �� k �� number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

��Ŀ���⣺���ڸ��������飬�ҵ����ִ�������k��Ԫ��
����˼·:
1. ��ͳ��ÿ��Ԫ�س��ֵĴ���
2. ������hashtable,����ÿһ�ִ���������һ��bucket��һ��bucketΪһ�����飬��ų��ִ���Ϊ��ͬ��
Ԫ�ء�Ȼ���ҳ���k��Ԫ�ؼ���

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
		//���ճ��ֵĴ�������buckets��
		vector<vector<int>>buckets(nums.size());
		for (auto iter = umap.begin(); iter != umap.end(); ++iter)
		{
			buckets[iter->second - 1].push_back(iter->first);
		}

		vector<int> res;
		//ͳ������k����
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
