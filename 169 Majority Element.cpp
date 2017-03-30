/*
leetcode 169. Majority Element

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist 
in the array.

解题思路：
1. 用一个hashmap保存每一个num的次数,返回次数大于n/2的数
2. 投票算法：在给定的n个数字中，Majority Element出现n次，那么其他出现n-k次。遍历数组，得到两个不同的
数字时，直接删掉。这两个数字中可能有一个为 Majority Element,也可能两个都不为Majority Element.
因为k 大于 n/2,所以在最差情况下(每次移除不同数字时都包含一个Majority Element),我们仍然能够保证最后得到的数字是Majority Element.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution
{
public:
	int majorityElement(vector<int>& nums) 
	{
		unordered_map<int, int> map;
		for (size_t i = 0; i < nums.size(); ++i)
			map[nums[i]]++;

		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		{
			if (it->second > nums.size() / 2)
				return it->first;
		}

		return 0;
	}

	//投票算法
	int majorityElement1(vector<int>& nums)
	{
		int res = 0;
		int count = 0; //用count记录比较过的且没有丢掉的数
		for (int i = 0; i < nums.size(); ++i)
		{
			if (count == 0)	//全部丢掉了,开始重新计算
			{
				count++;
				res = nums[i];
			}
			else if (res != nums[i]) //不等,
			{
				--count;
			}
			else
				++count;
		}

		return res;
	}

	//位操作时间复杂度: O(n)
	//我们需要32次迭代, 每一次计算所有n个数的第i位的1的个数。
	//由于众数一定存在，那么或者1的个数 > 0的个数 或者反过来(但绝不会相同)。 
	//众数的第i位一定是计数较多数字。
	int majorityElement2(vector<int>& nums)
	{
		vector<int> bitCount(32, 0);
		
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (nums[i] & (1 << j))
					bitCount[j]++;
			}
		}

		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (bitCount[i] > nums.size() / 2)
				ret += static_cast<int>(pow(2, i));
		}

		return ret;
	}
};

void test()
{
	vector<int> v{ 1,1,2,2,2,2,2,2,2,2,2,2,4,4,5,5,6,6,7 };
	vector<int> v1{1};
	Solution sol;
	cout << sol.majorityElement2(v) << endl;;
}

int main()
{
	test();

	return 0;
}