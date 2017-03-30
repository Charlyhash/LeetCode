/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

题目大意：判断t是不是s中字符乱序生成的字符串
解题思路：
方法1：对s和t排序，判断排序后的字符串是不是相等
方法2：打表，维护两个数组hashS和hashT,把s和t中的字符看成ASCII码，对每个出现的字母ch,
把对应的数组hash[ch]值+1。判断时比较hashS和hashT这两个数组是否相等。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) 
	{
		int len1 = s.size();
		int len2 = t.size();
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}

	bool isAnagram1(string s, string t)
	{
		int len1 = s.size();
		int len2 = t.size();
		if (len1 != len2)
			return false;
		vector<int> hashS(128, 0);
		vector<int> hashT(128, 0);
		
		for (int i = 0; i < len1; ++i)
		{
			hashS[s[i]]++;
			hashT[t[i]]++;
		}
		//由于只可能是小写字母，可以不用判断整个数组
		for (int i = 'a'; i <= 'z'; ++i)
		{
			if (hashS[i] != hashT[i])
				return false;
		}

		return true;
	} 
};

void test()
{
	Solution sol;
	string s1{ "aabcc" };
	string t1{ "abcac" };
	string s2{ "abc" };
	string t2{"bad"};
	cout << sol.isAnagram1(s1, t1) << endl;
	cout << sol.isAnagram(s2, t2) << endl;
}

int main()
{
	test();

	return 0;
}

