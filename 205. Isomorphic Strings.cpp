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

��Ŀ���⣺���ڸ������ַ���s��t����s�е���ĸ����ӳ����ܹ���Ϊt.����s�е���ĸֻ��ӳ��Ϊһ����ĸ��
����˼·��
�ⷨ1�����Դ���hash,һ���洢s[i]->t[i],һ��set�洢�Ѿ��ù���t[i]
�ⷨ2���Լ�����hash,s[i]->t[i]��t[i]->s[i]
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
		unordered_set<char> nset;//�Ѿ�ӳ�������ĸ�������ظ�ӳ��
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
			//��ӳ��
			if ((!vs[s[i]]) && (!vt[t[i]]))
			{
				vs[s[i]] = t[i];
				vt[t[i]] = s[i];
			}
			//��һ��ӳ�䣬��ô��һ�Զ�����������false
			else if ((!vs[s[i]]) || (!vt[t[i]]))
				return false;
			else
			{
				//����ӳ�䣬��ô��Ҫ����ӳ�����ǰ��ӳ��һ��
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