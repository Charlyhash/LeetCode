/*
leetcode 205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.

题目大意：对于给定的字符串s和t，把s中的字母经过映射后能够变为t.其中s中的字母只能映射为一个字母。
解题思路：
解法1：用自带的hash,一个存储s[i]->t[i],一个set存储已经用过的t[i]
解法2：自己建立hash,s[i]->t[i]和t[i]->s[i]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		
		unordered_map<char, char> nmap;	//s[i]->t[i]
		unordered_set<char> nset;//已经映射过的字母，不在重复映射
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (nmap.find(s[i]) != nmap.end()) //find the key
			{
				if (nmap[s[i]] != t[i])
					return false;
			}
			else
			{
				if (nset.find(t[i]) != nset.end())
					return false;
				else
				{
					nmap.insert({s[i], t[i]});
					nset.insert(t[i]);
				}
			}
		}

		return true;
	}

	bool isIsomorphic1(string s, string t)
	{
		vector<int> vs(128,0);//s[i]->t[i]
		vector<int> vt(128,0);//t[i]->s[i]
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			//无映射
			if ((!vs[s[i]]) && (!vt[t[i]]))
			{
				vs[s[i]] = t[i];
				vt[t[i]] = s[i];
			}
			//有一个映射，那么有一对多的情况，返回false
			else if ((!vs[s[i]]) || (!vt[t[i]]))
				return false;
			else
			{
				//都有映射，那么需要两个映射和以前的映射一样
				if (vs[s[i]] != t[i] || vt[t[i]] != s[i])
					return false;
			}
		}

		return true;
	}
};

void test()
{
	string s{ "ab" };
	string t{ "aa" };
	Solution sol;
	cout << sol.isIsomorphic(s, t) << endl;
	string t2{ "ad" };
	cout << sol.isIsomorphic(s, t2) << endl;
}

int main()
{
	test();

	return 0;
}