/*
leetcode 204. Count Primes
Description:

Count the number of prime numbers less than a non-negative number, n.

题目大意：求小于n个素数的个数
解题思路：打表，素数筛选法求素数，然后统计。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int countPrimes(int n) 
	{
		//打表
		vector<int> isPrime(n, true);
		for (int i = 2; i * i <= n; ++i)
		{
			if (isPrime[i])
			{
				//2...i，把这些数的倍数不是素数
				for (int j = i *i; j < n; j += i)
					isPrime[j] = false;
			}
		}

		int ret = 0;
		for (int i = 2; i < n; ++i)
			if (isPrime[i])
				++ret;

		return ret;
	}

};

void test()
{
	Solution sol;
	cout << sol.countPrimes(10) << endl;
}

int main()
{
	test();

	return 0;
}