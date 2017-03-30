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

����˼·��
1��ÿ��zigzag��size = 2*numRows-2���ַ�,һ��ѭ��
2��ɨ��ÿһ���С�ÿһ���Ȱ������ߵ��ַ��ӽ�ȥ��Ȼ���ٰ����ߵ��ַ��ټӽ�ȥ
2. ����ÿһ��ѭ��,j-i(iΪ��������)Ϊzigzag����ʼ�ַ��������ߵ��ǵ�����i���ַ���
������i������size-i����ô�����ߵ��ַ�Ϊ��(j-i)+(size-i)=j+size-2*i
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
				//���ڲ��ǵ�һ�к����һ�е��ַ�����Ҫ����б�����ߵ��ַ���
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