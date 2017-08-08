/*
leetocde 7. Reverse Integer
题目大意：翻转整数。x=123, return 321, x=-123, return -321.
如果超过32位有符号整数的范围，则返回0。

解题思路：
*/

#include <iostream>
using namespace std;


class Solution {
public:
	int reverse(int x) 
	{
		int ret = 0;
		while (x != 0)
		{
			int tail = x % 10;
			int newResult = ret * 10 + tail;
			if ((newResult - tail) / 10 != ret)
				return 0;
			ret = newResult;
			x = x / 10;
		}

		return ret;
	}

	int reverse1(int x)
	{
		long long numReversed = 0;
		int num = x;
		while (num != 0)
		{
			numReversed = numReversed * 10 + num % 10;
			num /= 10;
		}
		int y = numReversed;
		if (y == numReversed)
			return y;
		return 0;
	}
};

int main()
{
	Solution sol;
	cout << sol.reverse(1234567899) << endl;
	cout << sol.reverse(123) << endl;
	cout << sol.reverse(-123) << endl;
	return 0;
}