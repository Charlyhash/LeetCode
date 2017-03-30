/*
leetcode : 3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

题目大意：找出最长的没有重复元素的子序列
解题思路：贪心
维护两个指针left和right，一个指向头，另一个向后遍历，把遍历过的字符记录在数组中。当后面出现的字符已经在
前面出现过了，就让left到当前位置，right继续向后遍历。每次都更新最大的长度
*/

#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int left = -1; 
		int right = 0;
		int res = 0;
		int len = s.size();

		//记录每个字母出现的位置
		vector<int> v(256, -1);
		if (len == 0 || len == 1)
			return len;
		//traverse the string s
		for (; right < len; ++right)
		{
			// when the char s[right] occurs, the left pos should chang
			if (v[s[right]] > left)
				left = v[s[right]];
			//add char/position to the vector
			v[s[right]] = right;
			//update the max result
			res = max(res, right - left);
		}

		return res;

	}

};

void test()
{
	Solution sol;
	int ret = sol.lengthOfLongestSubstring("abcabcbb");
	int ret1 = sol.lengthOfLongestSubstring("au");
	cout << ret << endl;
	cout << ret1 << endl;
}

int main()
{
	test();

	return 0;
}