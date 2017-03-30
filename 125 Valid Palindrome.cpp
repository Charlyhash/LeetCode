/*
leetcode 125. Valid Palindrome
��Ŀ���⣺�ж�һ�仰ʱ��Ϊ���ģ�ֻ������ĸ�����Դ�Сд��
����˼·��
1���ж�һ���ַ��Ƿ�Ϊ���ֻ�����ĸ
2���ڱȽϵ�ʱ�򲻷ִ�Сд����˴�дֱ��ȫ��תΪСд
3�����жϻ���ʱֱ�ӱȽ���β�������ַ�
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.length();

		if (len == 0 || len == 1)
			return true;
		int i = 0, j = len-1;
		while (1)
		{
			while (!isAlphaNumeric(s[i]) && i < len)
				++i;
			while (!isAlphaNumeric(s[j]) && j >= 0)
				--j;
			if (i >= j)
				return true;
			if (toLower(s[i]) != toLower(s[j]))
				return false;
			++i;
			--j;
		}
	}

private:
	bool isAlphaNumeric(char c)
	{
		if ('a' <= c  && c <= 'z')
			return true;
		if ('A' <= c && c <= 'Z')
			return true;
		if ('0' <= c && c <= '9')
			return true;
		return false;
	}

	char toLower(char c)
	{
		if ('A' <= c && c <= 'Z')
			return c - ('A' - 'a');
		else
			return c;
	}
};

void test_isPalindrome()
{
	Solution sol;
	//cout << sol.isPalindrome("!!!") << endl;
	cout << sol.isPalindrome("0P") << endl;
	cout << sol.isPalindrome("A man, a plan, a canal : Panama") << endl;
}

int main()
{
	test_isPalindrome();

	return 0;
}