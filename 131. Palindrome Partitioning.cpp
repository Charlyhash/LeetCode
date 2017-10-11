/*
leetcode 131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
[
	["aa","b"],
	["a","a","b"]
]

解题思路：
DFS:每次判断当前字符串是否为回文字符串，如果是移动到下一个位置判断，直到到达字符串最末尾。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution1 {
public:
	vector<vector<string>> partition(string s) 
	{
		vector<vector<string>> ret;
		if (!s.size())
			return ret;
		vector<string> tmp;
		DFS(ret, s, tmp);

		return ret;
	}

	void DFS(vector<vector<string>>& ret, string s, vector<string> tmp)
	{
		if (!s.size())
			ret.push_back(tmp);

		for (int i = 1; i <= s.size(); ++i)
		{
			string str = s.substr(0, i);
			if (IsPalindrome(str))
			{
				tmp.push_back(str);
				DFS(ret, s.substr(i), tmp);
				tmp.pop_back();
			}
		}
	}

	bool IsPalindrome(string s)
	{
		if (s == "")
			return true;
		int len = s.size();
		for (auto i = 0; i < len / 2; ++i)
		{
			if (s[i] != s[len - 1 - i])
				return false;
		}

		return true;
	}
};

//使用DP加速
class Solution {
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> ret;
		if (!s.size())
			return ret;
		vector<string> tmp;
		int len = s.size();
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
		//构造dp,当s[i...j]为回文时，dp[i][j] = true
		for (int l = 1; l <= len; ++l)
		{
			for (int i = 0; i < len; ++i)
			{
				int j = i + l - 1;
				if (j >= len)
					break;
				dp[i][j] = ((i+1 > j - 1) || dp[i + 1][j - 1]) && (s[i] == s[j]);
			}
		}

		//for (int i = 0; i < len; ++i) {
		//	for (int j = 0; j < len; ++j)
		//		cout << dp[i][j] << " ";
		//	cout << endl;
		//}
		
		DFS(ret, s, 0, tmp, dp);

		return ret;
	}

	void DFS(vector<vector<string>>& ret, string& s, int start, vector<string>& tmp, vector<vector<bool>>& dp)
	{
		int len = s.size();
		if (start == len)
		{
			ret.push_back(tmp);
			return;
		}

		for (int i = start; i < len; ++i)
		{
			if(!dp[start][i])
				continue;
			else
			{
				tmp.push_back(s.substr(start, i - start + 1));
				DFS(ret, s, i + 1, tmp, dp);
				tmp.pop_back();
			}
		}
	}
};

void TEST()
{
	Solution sol;
	vector<vector<string>> ret = sol.partition("aab");

	for (auto v : ret)
	{
		for (auto s : v)
			cout << s << " ";
		cout << endl;
	}

	
}


int main()
{
	TEST();

	return 0;
}