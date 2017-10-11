/*
leetcode : 3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

��Ŀ���⣺�ҳ����û���ظ�Ԫ�ص�������
����˼·��̰��
ά������ָ��left��right��һ��ָ��ͷ����һ�����������ѱ��������ַ���¼�������С���������ֵ��ַ��Ѿ���
ǰ����ֹ��ˣ�����left����ǰλ�ã�right������������ÿ�ζ��������ĳ���
*/

#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int left = -1; 
		int right = 0;
		int res = 0;
		int len = s.size();

		//��¼ÿ����ĸ���ֵ�λ��
		vector<int> v(256, -1);
		if (len == 0 || len == 1)
			return len;
		//traverse the string s
		for (; right < len; ++right)
		{
			//���rightλ�õ��ַ����ֹ������ҳ��ֵ�λ�ô���left��˵����
			//��left֮��ڶ��γ��֣����ظ��ˣ������Ҫ����left
			if (v[s[right]] > left)
				left = v[s[right]];
			//add char/position to the vector
			v[s[right]] = right; //�����ַ���s[right]���ֵ�λ��
			//update the max result
			res = max(res, right - left); //����max
		}

		return res;

	}

};

void test()
{
	Solution sol;
	int ret = sol.lengthOfLongestSubstring("abcabcbb");
	int ret1 = sol.lengthOfLongestSubstring("au");
	cout << ret << endl;
	cout << ret1 << endl;
}

int main()
{
	test();

	return 0;
}