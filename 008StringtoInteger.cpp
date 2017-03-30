#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) 
	{
		//int ret = 0;
		//int sign = 1;
		//int len = str.length();
		//int i = 0;

		//while (i < str.size())
		//{
		//	if (str[i] == '-')
		//	{
		//		sign = -1;
		//		++i;
		//	}
		//	else if (str[i] == '+')
		//		++i;
		//	
		//	if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		//		++i;
		//}
		//while (i < len)
		//{
		//	if (isdigit(str[i]))
		//		ret = ret * 10 + str[i] - '0';
		//	else
		//		break;
		//}

		//return sign * ret;
		int ret = 0;
		bool overflow = false;
		int sign = 1;   // default is '+'  
		int i = 0;
		int len = str.length();

		while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			++i;
		if (i == len)
			return 0;

		// get sign  
		if (str[i] == '-') {
			++i;
			sign = -1;
		}
		else if (str[i] == '+')
			++i;

		while (i < len) {
			if (!isdigit(str[i]))
				break;
			if ((sign == 1 && ret >(INT_MAX - (str[i] - '0')) / 10) ||
				(sign == -1 && -ret < (INT_MIN + (str[i] - '0')) / 10)) {
				overflow = true;
				break;
			}
			ret = ret * 10 + (str[i] - '0');
			++i;
		}
		if (overflow)
			ret = (sign == 1) ? INT_MAX : INT_MIN;
		else
			ret *= sign;
		return ret;
	}
};

int main()
{
	string str = "-+  1 2 3";
	Solution sol;

	cout << sol.myAtoi(str) << endl;

	return 0;
}