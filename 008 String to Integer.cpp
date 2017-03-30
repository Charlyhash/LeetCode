/*
Implement atoi to convert a string to an integer.

Requirements for atoi:
1. The function first discards as many whitespace characters as necessary until the first
non-whitespace character is found.
2. Then, starting from this character, takes an optional initial plus or minus sign followed
by as many numerical digits as possible, and interprets them as a numerical value.
3. The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.
4. If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is empty or it
 contains only whitespace characters, no conversion is performed.
5. If no valid conversion could be performed, a zero value is returned.
6. If the correct value is out of the range of representable values,
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0;
        bool sign = true;
        if (str.size() == 0) //处理空字符串
            return 0;
        while (str[i] == ' ') //处理前导的空字符
            ++i;
        if (str[i] == '-')  //处理符号
        {
            sign = false;
            ++i;
        }
        else if (str[i] == '+')
        {
            sign = true;
            ++i;
        }
        while (str[i] == '0') //处理数字前面的0
            ++i;

//LONG_MIN	Minimum value for an object of type long int	-2147483647 (-231+1) or less*
//LONG_MAX	Maximum value for an object of type long int	2147483647 (231-1) or greater*
        long int res = 0;
        long int tmp = 0;

        while (i < str.length() && str[i] >= '0' && str[i] <= '9' )
        {
            tmp = res;
            res = res*10 +  reinterpret_cast<int>(str[i]-'0');
            if (res > INT_MAX)
                return sign == true ? INT_MAX : INT_MIN;
            ++i;
        }

        return sign == true ? res : res * (-1);
    }
};

void TEST()
{
    Solution sol;
    string s="   -000343245";

    cout << sol.myAtoi(s) << endl;
}

int main()
{
    TEST();

    return 0;
}
