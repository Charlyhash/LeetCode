/*
leetcode 125. Valid Palindrome
题目大意：判断一句话时候为回文，只考虑字母，忽略大小写。
解题思路：
1、判断一个字符是否为数字或者字母
2、在比较的时候不分大小写，因此大写直接全部转为小写
3、在判断回文时直接比较首尾的两个字符
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.length();

		if (len == 0 || len == 1)
			return true;
		int i = 0, j = len-1;
		while (1)
		{
			while (!isAlphaNumeric(s[i]) && i < len)
				++i;
			while (!isAlphaNumeric(s[j]) && j >= 0)
				--j;
			if (i >= j)
				return true;
			if (toLower(s[i]) != toLower(s[j]))
				return false;
			++i;
			--j;
		}
	}

private:
	bool isAlphaNumeric(char c)
	{
		if ('a' <= c  && c <= 'z')
			return true;
		if ('A' <= c && c <= 'Z')
			return true;
		if ('0' <= c && c <= '9')
			return true;
		return false;
	}

	char toLower(char c)
	{
		if ('A' <= c && c <= 'Z')
			return c - ('A' - 'a');
		else
			return c;
	}
};

void test_isPalindrome()
{
	Solution sol;
	//cout << sol.isPalindrome("!!!") << endl;
	cout << sol.isPalindrome("0P") << endl;
	cout << sol.isPalindrome("A man, a plan, a canal : Panama") << endl;
}

int main()
{
	test_isPalindrome();

	return 0;
}