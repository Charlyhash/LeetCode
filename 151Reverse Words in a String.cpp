/*
leetcode 151. Reverse Words in a String

Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

解题思路：
用一个临时string保存翻转后的字符。
从最后开始往前扫描字符串，去掉后置的空格，当遇到一个单词时，用一个临时的变量存储这个单词，
得到的是一个反转的单词，因此要reverse.然后将得到的单词添加到临时字符串中。一次可以得到一个单词。
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) 
	{
		string ret;
		int i = s.length() - 1;
		while (i >= 0)
		{
			while (i >= 0 && s[i] == ' ')
				--i;
			if (i < 0)
				break;
			if (!ret.empty())
				ret.push_back(' ');
			string tmp;
			while (i >= 0 && s[i] != ' ')
			{
				tmp.push_back(s[i]);
				--i;
			}
			reverse(tmp.begin(), tmp.end());
			
			ret += tmp;
		}

		s = ret;
	}
};

void TEST()
{
	Solution sol;
	string s("the sky is blue");
	sol.reverseWords(s);
	cout << s << endl;
}

int main()
{
	TEST();
	return 0;
}