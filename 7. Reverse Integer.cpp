/*
leetocde 7. Reverse Integer
��Ŀ���⣺��ת������x=123, return 321, x=-123, return -321.
�������32λ�з��������ķ�Χ���򷵻�0��

����˼·��
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