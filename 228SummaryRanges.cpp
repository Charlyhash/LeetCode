/*
leetcode 228. Summary Ranges
题目大意：对于给定的排序数组(无重复元素)，返回元素范围
譬如说：[0,1,2,4,5,7]，返回["0->2","4->5","7"]
解题思路：
1、确定范围：如果nums[end+1]==nums[end]+1,说明还是在一个返回
否则的话，就确定了一个返回。
2、格式输出：写一个函数直接输出。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string format(int begin, int end)
	{
		char buffer[32];
		if (end == begin)
			sprintf(buffer, "%d", begin);
		else
			sprintf(buffer, "%d->%d", begin, end);

		return string(buffer);
	}
	vector<string> summaryRanges(vector<int>& nums) 
	{
		vector<string> result;
		if (nums.size() == 0)
			return result;
		int begin, end;
		begin = end= nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == end + 1)
			{
				end = nums[i];
			}
			else
			{
				result.push_back(format(begin, end));
				begin = end = nums[i];
			}
		}

		result.push_back(format(begin, end));

		return result;
		
	}
};

void test_summaryRanges()
{
	Solution sol;
	vector<int> nums{0,1,2,4,5,7};
	vector<string> vecString = sol.summaryRanges(nums);
	for (auto s : vecString)
		cout << s << " ";
	cout << endl;
}

int main()
{
	test_summaryRanges();

	return 0;
}
