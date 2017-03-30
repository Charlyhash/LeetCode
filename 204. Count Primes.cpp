/*
leetcode 204. Count Primes
Description:

Count the number of prime numbers less than a non-negative number, n.

��Ŀ���⣺��С��n�������ĸ���
����˼·���������ɸѡ����������Ȼ��ͳ�ơ�
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
		//���
		vector<int> isPrime(n, true);
		for (int i = 2; i * i <= n; ++i)
		{
			if (isPrime[i])
			{
				//2...i������Щ���ı�����������
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