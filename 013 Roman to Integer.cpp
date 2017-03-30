/*
leetcode:13. Roman to Integer
罗马数字转为整数
罗马数字有一下几种
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000
基本规则：
1、相同的数字连写，所表示的数等于这些数字相加得到的数。 “XXX”表示的是10*3=30
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如CL是150
3、小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如XL是40
4、在一个数的上面画一条横线，表示这个数增值 1,000 倍，如V(上划线)是50000
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) 
	{
		int len = s.length();
		if (len == 0)
			return 0;
		map <char, int> r;
		r['I'] = 1;
		r['V'] = 5;
		r['X'] = 10;
		r['L'] = 50;
		r['C'] = 100;
		r['D'] = 500;
		r['M'] = 1000;

		int i = len - 1;
		int ret = r[s[i]];
		--i;
		while (i >= 0)
		{
			//让这个数和右边的数字比较
			if (r[s[i]] < r[s[i + 1]])		//这个数比右边的数小，要减，比如IV,为5-1;
				ret -= r[s[i--]];
			else							//这个数比右边的数大或者相等，要加，如VII，为5+1+1
				ret += r[s[i--]];			
		}

		return ret;
	}
};

void test_romanToInt()
{
	Solution sol;
	cout << "空字符 = " << sol.romanToInt("") << endl;
	cout << "X = " << sol.romanToInt("X") << endl;
	cout << "MCMLXXX = " << sol.romanToInt("MCMLXXX") << endl;
	cout << "III = " << sol.romanToInt("III") << endl;
	cout << "IV = " << sol.romanToInt("IV") << endl;
	cout << "VI = " << sol.romanToInt("VI") << endl;
	cout << "XIX = " << sol.romanToInt("XIX") << endl;
	cout << "XX = " << sol.romanToInt("XX") << endl;
	cout << "XLV = " << sol.romanToInt("XLV") << endl;
}
int main()
{
	test_romanToInt();

	return 0;
}
/*
空字符 = 0
X = 10
MCMLXXX = 1980
III = 3
IV = 4
VI = 6
XIX = 19
XX = 20
XLV = 45
*/

