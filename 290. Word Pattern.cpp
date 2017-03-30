/*
leetcode 290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in 
pattern and a non-empty word in str.
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase 
letters separated by a single space.

题目大意：根据给定的字符模式，判断字符串中的单词模式是否和字符串模式相同
解题思路：和leetcode 205. Isomorphic Strings有点像。如果把str解析成vector<string>就一样
的思路了
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> v;
		StringSplit(str, " ", v);
		if (pattern.size() != v.size())
			return false;
		//for (auto s : v)
		//	cout << s << ",";
		//cout << endl;
		unordered_map<char, string> nmap;//pattern[i]->v[i]
		unordered_set<string> nset;//pattern[i]
		int len = pattern.size();

		for (int i = 0; i < len; ++i)
		{
			if (nmap.find(pattern[i]) != nmap.end())
			{
				if (nmap[pattern[i]] != v[i])
					return false;
			}
			else
			{
				if (nset.find(v[i]) != nset.end())
					return false;
				else
				{
					nset.insert(v[i]);
					nmap.insert({ pattern[i], v[i] });
				}
			}
			
		}
		
		return true;
	}

	void StringSplit(string str, string c, vector<string>& v)
	{
		size_t pos1, pos2;
		pos2 = str.find(c);
		pos1 = 0;
		while (string::npos != pos2)
		{
			v.push_back(str.substr(pos1, pos2 - pos1));

			pos1 = pos2 + c.size();
			pos2 = str.find(c, pos1);
		}

		if (pos1 != str.length())
			v.push_back(str.substr(pos1));
	}
};

void test()
{
	Solution sol;
	cout << sol.wordPattern("jquery", "jquery") << endl;
	cout << sol.wordPattern("abba","dog cat cat dog") << endl;
}

int main()
{
	test();

	return 0;
}