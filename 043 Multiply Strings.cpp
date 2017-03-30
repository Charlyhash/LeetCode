/*
Leetcode 43. Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
解题思路：模拟手算。第i位乘以第j位得到的是(i+j)位的数

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
		//先要反转，把最低位放在0的位置
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int tmp = 0;
		string s(num1.length() + num2.length(), '0');
		for (size_t i = 0; i < num1.length(); ++i)
		{
			for (size_t j = 0; j < num2.length(); ++j)
			{
				tmp = (num1[i] - '0') * (num2[j] - '0');		//tmp为i位*j位
				//把进位加到i+j+1位上
				s[i + j + 1] = s[i + j + 1] - '0' + (s[i + j] - '0' + tmp) / 10 + '0';
				//非进位的部分留在i+j位上
				s[i + j] = (s[i + j] - '0' + tmp) % 10 + '0';
			}
		}
		//处理完成后反转
		reverse(s.begin(), s.end());
		//去掉前面的0
		auto pos = s.find_first_not_of('0');
		if (pos == string::npos)	//为0的情况
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