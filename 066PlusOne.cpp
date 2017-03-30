/*
leetcode 66. Plus One
题目大意：给定一个非负整数，存储在数组中，把这个数字加1，这个数的最高位在最前面。
解题思路：如果这个数的最低位为小于9，直接加到最低位去
如果这个数的最低位为9分为2中情况：
1、没有到最高位（也就是digits[0]）,让这一位为0，然后处理高它一位的情况，也是加1
2、如果到了最高位，说明了，这个数是很多9，不然加1怎么可能会进到最高位呢，因此让最高为为1
然后压入一个0.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		if (digits.size() == 0)
			return digits;
		for (size_t i = digits.size() - 1; i >= 0; --i)
		{
			//处理小于9的情况，加一后直接返回
			if (digits[i] < 9)
			{
				++digits[i];
				return digits;
			}
			else  //处理等于9的情况
			{
				if (i != 0)		//没有到最高位
					digits[i] = 0;
				else			//到了最高位了
				{
					digits[0] = 1;
					digits.push_back(0);
					return digits;
				}
			}
		}
	}
};

void test_PlusOne()
{
	vector<int> vecInt1{ 9,9,9,9,9 };
	vector<int> vecInt2{ 8,9,9,9,9 };
	Solution sol;
	vector<int> result1;
	result1 = sol.plusOne(vecInt1);
	for (auto i : result1)
		cout << i << " ";
	cout << endl;
	vector<int> result2;
	result2 = sol.plusOne(vecInt2);
	for (auto i : result2)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test_PlusOne();

	return 0;
}