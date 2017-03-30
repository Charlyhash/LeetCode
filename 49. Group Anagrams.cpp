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

��Ŀ���⣺����������ַ������飬������ͬ��ĸ��ɵĵĵ��ʷ�Ϊһ�顣
����˼·��ʹ��hash,ÿһ��sort���string��Ӧ��һ��vector<string>

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
		//����ÿһ��string����sort,Ȼ�����sort����Ϊkey,ԭstring��Ϊvalue��һ��Ԫ�ء�
		for (auto str : strs)
		{
			string tmp = str;
			sort(tmp.begin(), tmp.end());
			umap[tmp].push_back(str);
		}
		//umap����ľ����Ѿ������string��
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