/*
leetcode 376. Wiggle Subsequence

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

解题思路：dp
用两个数组up和down，up[i],down[i]分别表示以nums[i]结尾的上升或下降的最长序列长度
递推关系有如下几种：
1、nums[i] > nums[i - 1]
up[i] = down[i - 1] + 1;
down[i] = down[i - 1];
2、nums[i] < nums[i - 1]
up[i] = up[i - 1];
down[i] = up[i - 1] + 1;
3、相等：
up[i] = up[i - 1];
down[i] = down[i - 1];

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums)
	{
		int length = nums.size();
		if (length == 0 || length == 1)
			return length;
		vector<int> up(nums.size(), 0);
		vector<int> down(nums.size(), 0);
		up[0] = down[0] = 1;	//初始条件
		for (int i = 1; i < length; ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				up[i] = down[i - 1] + 1;
				down[i] = down[i - 1];
			}
			else if (nums[i] < nums[i - 1])
			{
				up[i] = up[i - 1];
				down[i] = up[i - 1] + 1;
			}
			else
			{
				up[i] = up[i - 1];
				down[i] = down[i - 1];
			}
			//cout << up[i] << " " << down[i] << endl;
		}

		return max(up[length-1], down[length-1]);
	}
};

void test()
{
	vector<int> nums1{ 1,7,4,9,2,5 };
	vector<int> nums2{ 1,17,5,10,13,15,10,5,16,8 };
	vector<int> nums3{ 1,2,3,4,5,6,7,8,9 };
	Solution sol;
	cout << sol.wiggleMaxLength(nums1) << endl;
	cout << sol.wiggleMaxLength(nums2) << endl;
	cout << sol.wiggleMaxLength(nums3) << endl;
}

int main()
{
	test();

	return 0;

}