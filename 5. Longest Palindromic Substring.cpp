/*
leetcode 5. Longest Palindromic Substring
题目大意：对于所给的字符串s, 输出s的最长回文字串
解题思路：分别找到以每个字母为中心的回文字符串，然后返回最长的回文字符串
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s)
	{
		int n = s.size();
		if (n == 0 || n == 1)
			return s;
		string ret = s.substr(0, 1);
		for (int i = 0; i < n - 1; ++i)
		{
			string p1 = centerString(s, i, i);
			if (p1.size() > ret.size())
				ret = p1;
			string p2 = centerString(s, i, i + 1);
			if (p2.size() > ret.size())
				ret = p2;
		}

		return ret;
	}

private:
	string centerString(string s, int c1, int c2)
	{
		int l = c1, r = c2;
		int n = s.size();
		while (l >= 0 && r <= n - 1 && s[l] == s[r])
		{
			l--;
			r++;
		}
		return s.substr(l + 1, r - l - 1);
	}
};

int main()
{
	string s("babad");
	Solution sol;
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}