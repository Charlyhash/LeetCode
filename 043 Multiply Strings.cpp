/*
Leetcode 43. Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
����˼·��ģ�����㡣��iλ���Ե�jλ�õ�����(i+j)λ����

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) 
	{
		//��Ҫ��ת�������λ����0��λ��
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int tmp = 0;
		string s(num1.length() + num2.length(), '0');
		for (size_t i = 0; i < num1.length(); ++i)
		{
			for (size_t j = 0; j < num2.length(); ++j)
			{
				tmp = (num1[i] - '0') * (num2[j] - '0');		//tmpΪiλ*jλ
				//�ѽ�λ�ӵ�i+j+1λ��
				s[i + j + 1] = s[i + j + 1] - '0' + (s[i + j] - '0' + tmp) / 10 + '0';
				//�ǽ�λ�Ĳ�������i+jλ��
				s[i + j] = (s[i + j] - '0' + tmp) % 10 + '0';
			}
		}
		//������ɺ�ת
		reverse(s.begin(), s.end());
		//ȥ��ǰ���0
		auto pos = s.find_first_not_of('0');
		if (pos == string::npos)	//Ϊ0�����
			return "0";
		else
			return s.substr(pos);
	}
};

void TEST()
{
	Solution sol;
	string s1 = "123";
	string s2 = "234";

	cout << sol.multiply(s1, s2) << endl;

}

int main()
{
	TEST();

	return 0;
}