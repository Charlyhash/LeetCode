/*
leetcode 49. Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note: All inputs will be in lower-case.

题目大意：对与给定的字符串数组，把由相同字母组成的的单词分为一组。
解题思路：使用hash,每一个sort后的string对应与一个vector<string>

*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		unordered_map<string, vector<string>> umap;
		vector<vector<string>> ret;
		//对于每一个string，先sort,然后放入sort后作为key,原string作为value的一个元素。
		for (auto str : strs)
		{
			string tmp = str;
			sort(tmp.begin(), tmp.end());
			umap[tmp].push_back(str);
		}
		//umap保存的就是已经分组的string了
		for (auto& iter : umap)
		{
			ret.push_back(iter.second);
		}

		return ret;
	}
};

void test()
{
	vector<string> v{ "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution sol;
	vector<vector<string>> ret = sol.groupAnagrams(v);
	for (auto v : ret)
	{
		for (auto s : v)
			cout << s << " ";
		cout << endl;
	}
}

int main()
{
	test();

	return 0;
}