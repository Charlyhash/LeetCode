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

����˼·��
��һ����ʱstring���淭ת����ַ���
�����ʼ��ǰɨ���ַ�����ȥ�����õĿո񣬵�����һ������ʱ����һ����ʱ�ı����洢������ʣ�
�õ�����һ����ת�ĵ��ʣ����Ҫreverse.Ȼ�󽫵õ��ĵ�����ӵ���ʱ�ַ����С�һ�ο��Եõ�һ�����ʡ�
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