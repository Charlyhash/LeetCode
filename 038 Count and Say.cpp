/*
leetcode 38. Count and Say
��Ŀ���⣺����ÿ���ַ�����Ʃ��˵
1 ���� 11
11 ���� 21
21 ���� 1211
...
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n)
	{
		if (n == 1)
			return "1";
		string ret = "1";
		for (int i = 1; i < n; ++i)
			ret = readString(ret);

		return ret;
	}

	string readString(string str)
	{
		int len = str.size();
		if (len == 1)
			return "1" + str;

		char c;
		int count = 1;		//���ֵĴ���
		string ret="";
		int i = 0;
		while (i < len)
		{
			c = str[i++];
			while (c == str[i] && i < len)
			{
				++count;	//���ֵĴ�������1
				++i;		//�ж���һ���ַ�
			}
			//if (i == len)
			ret = ret + char(count + '0') + c;
			count = 1;
		}

		return ret;
	}

};

void test_readString()
{
	Solution sol;
	cout << sol.readString("1") << endl;
	
}

void test_countAndSay()
{
	Solution sol;
	cout << sol.countAndSay(2) << endl;
	for (int i = 1; i < 10; ++i)
		cout <<  i << ":"<< sol.countAndSay(i) << endl;
}

int main()
{
	//test_readString();
	test_countAndSay();
	return 0;
}