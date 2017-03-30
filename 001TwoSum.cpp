/*
leetcode 001 TwoSum
题目大意：从给定的一组数中找到两个数的和为target.返回两个数的序号，假设每次输入只有一组解
解题思路：
1、暴力搜索：对于每个数去找后面和它的和为target的数，如果找到了就返回
我好像第一次提交用暴力搜索竟然过了。
2、hash：先进行hash映射，<key,value>为 <nums[i], i>，对于每一个数，可以在O(1)的时间找到
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//暴力搜索
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> index;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = i+1; j < nums.size(); ++j)
			{
				if ((nums[i] + nums[j]) == target)
				{
					index.push_back(i);
					index.push_back(j);
					return index;
				}
			}
		}
	}

	//hash
	vector<int> twoSum1(vector<int>& nums, int target)
	{
		unordered_map<int, int> mapping;			//hash map
		vector<int> result;							//result
		for (size_t i = 0; i < nums.size(); ++i)	//O(n)：进行hash
		{
			mapping[nums[i]] = i;
		}
		for (size_t i = 0; i < nums.size(); ++i)
		{
			const int gap = target - nums[i];							//找到这个数
			if (mapping.find(gap) != mapping.end() && mapping[gap]!=i)	//找到了，O(1)
			{
				result.push_back(i + 1);								//index 1
				result.push_back(mapping[gap] + 1);						//index 2
				break;
			}
		}
		return result;
	}
};

void test_twoSum()
{
	Solution sol;
	vector<int> index;
	vector<int> nums{4,71,15,3,9,17,13,25,1,33,0};
	int target = 30;
	index = sol.twoSum(nums, target);
	//输出
	for (auto i : index)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test_twoSum1()
{
	Solution sol;
	vector<int> index;
	vector<int> nums{ 4,71,15,3,9,17,13,25,1,33,0 };
	int target = 30;
	index = sol.twoSum1(nums, target);
	//输出
	for (auto i : index)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	test_twoSum();
	
	return 0;
}
