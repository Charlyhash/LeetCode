/*
leetcode 263. Ugly Number
题目大意：检查一个数是否为Ugly Number(只有2，3，5这几个基本因子)，1也是
譬如说6=2*3，12=2*2*3，因此6，12都是Ugly Number;14=2*7就不是Ugly Number
解题思路：对于一个数num,如果是2的倍数就一直除以2，是3的倍数就一直除以3，是
5的倍数就一直除以5.除完之后如果为1，就说明是Ugly Number,否则就还有其他都基本
因子，不是Ugly Number.
*/

#include <iostream>

class Solution {
public:
	bool isUgly(int num)
	{
		if (num <= 0)
			return false;
		if (num == 1)
			return true;

		while (num >= 2 && num % 2 == 0)
			num = num / 2;
		while (num >= 3 && num % 3 == 0)
			num = num / 3;
		while (num >= 5 && num % 5 == 0)
			num = num / 5;

		return num == 1;
	}
};

void test_isUgly()
{
	Solution sol;
	std::cout << "2: " << sol.isUgly(2) << std::endl;
	std::cout << "12: " << sol.isUgly(12) << std::endl;
	std::cout << "14: " << sol.isUgly(14) << std::endl;
}
int main()
{
	test_isUgly();

	return 0;
}