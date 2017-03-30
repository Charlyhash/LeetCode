/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

��Ŀ���⣺�ж�t�ǲ���s���ַ��������ɵ��ַ���
����˼·��
����1����s��t�����ж��������ַ����ǲ������
����2�����ά����������hashS��hashT,��s��t�е��ַ�����ASCII�룬��ÿ�����ֵ���ĸch,
�Ѷ�Ӧ������hash[ch]ֵ+1���ж�ʱ�Ƚ�hashS��hashT�����������Ƿ���ȡ�
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) 
	{
		int len1 = s.size();
		int len2 = t.size();
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}

	bool isAnagram1(string s, string t)
	{
		int len1 = s.size();
		int len2 = t.size();
		if (len1 != len2)
			return false;
		vector<int> hashS(128, 0);
		vector<int> hashT(128, 0);
		
		for (int i = 0; i < len1; ++i)
		{
			hashS[s[i]]++;
			hashT[t[i]]++;
		}
		//����ֻ������Сд��ĸ�����Բ����ж���������
		for (int i = 'a'; i <= 'z'; ++i)
		{
			if (hashS[i] != hashT[i])
				return false;
		}

		return true;
	} 
};

void test()
{
	Solution sol;
	string s1{ "aabcc" };
	string t1{ "abcac" };
	string s2{ "abc" };
	string t2{"bad"};
	cout << sol.isAnagram1(s1, t1) << endl;
	cout << sol.isAnagram(s2, t2) << endl;
}

int main()
{
	test();

	return 0;
}

