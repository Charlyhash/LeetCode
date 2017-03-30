/*
leetcode 202. Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of 
the squares of its digits, and repeat the process until the number equals 
1 (where it will stay), or it loops endlessly in a cycle which does not 
include 1. Those numbers for which this process ends in 1 are happy numbers.

��Ŀ���⣺�ж�һ�����ǲ���happy number,�������ÿ��λ�ϵ���ƽ�����ֱ�����Ϊ1
����˼·��
����1����һ��set��¼���ֵ����֣�����ٴγ��֣�˵����ѭ����Ϊhappy number.������뵽set��
Ȼ�����ÿһλ��ƽ�������Ϊ1���򷵻�true,��������жϡ�

����2���ݹ顣����Ҫ֪��1-9�ǲ���happy number.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int num =  n;
		unordered_set<int> uset;
		while (uset.find(num) == uset.end())
		{
			int tmp = 0;
			uset.insert(num);
			while (num)
			{
				tmp += pow(num % 10, 2);
				num /= 10;
			}
			//cout << tmp << endl;
			num = tmp;
			if (num == 1)
				return true;
		}
		return false;
	}

	bool isHappy1(int n) {
		if (1 <= n && n <= 9) {
			return n == 1 || n == 7;
		}
		int num = 0;
		while (n)
		{
			num += pow(n % 10, 2);
			n /= 10;
		}

		return isHappy(num);
	}
};

void test()
{
	Solution sol;
	cout << sol.isHappy(89) << endl;
	

}

int main()
{
	test();

	return 0;
}
