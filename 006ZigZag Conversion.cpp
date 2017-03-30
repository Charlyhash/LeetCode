/*
leetcode 6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

解题思路：
1、每个zigzag是size = 2*numRows-2个字符,一个循环
2、扫描每一个行。每一行先把往下走的字符加进去，然后再把上走的字符再加进去
2. 对于每一个循环,j-i(i为所在行数)为zigzag的起始字符，往上走的是倒数第i个字符。
倒数第i个就是size-i，那么往上走的字符为：(j-i)+(size-i)=j+size-2*i
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows)
	{
		if (s == "" || s.length() == 0 || numRows <= 0)
			return "";
		if (numRows == 1)
			return s;
		string ret;
		size_t size = 2 * numRows - 2;
		for (size_t i = 0; i < numRows; ++i)
		{
			for (size_t j = i; j < s.length(); j += size)
			{
				ret.push_back(s[j]);
				//对于不是第一行和最后一行的字符，都要加入斜向上走的字符。
				if (i != 0 && i != numRows - 1 && j + size - 2 * i < s.length())
					ret.push_back(s[j + size - 2 * i]);
			}
		}

		return ret;
	}
};

void TEST()
{
	Solution sol;
	string s("PAYPALISHIRING");
	cout << sol.convert(s, 3) << endl;
}

int main()
{
	TEST();

	return 0;
}