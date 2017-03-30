/*
 leetcode 166. Fraction to Recurring Decimal

 Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

 If the fractional part is repeating, enclose the repeating part in parentheses.

 For example,

 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".
 Show Hint


 ��Ŀ���⣺��С����ʾ�����Ľ���������ѭ����С������ô�����ű�ʾѭ���Ĳ���
 ����˼·��
 1. �ȵõ���������
 2. *10֮���ٳ��õ�С������
 3. �ж�ѭ���ķ�������һ��hashmap��¼ÿһ���������������ٴγ���ʱ�ͽ���ѭ��
 ע�⣺
 1. ���ŵ��ж�
 2. ������תΪ����ʱ���ܻ����
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		if (numerator == 0)
			return "0";

		string ret;
		//decide the sign of the result
		if ((numerator > 0) ^ (denominator > 0))
			ret += '-';  // the sign is '-'
						 // ret =  k * denominator + r;
		long n = numerator;
		long d = denominator;
		n = abs(n);
		d = abs(d);
		long k = n / d;
		long r = n % d;
		ret += to_string(k);
		if (!r)
			return ret;
		else
			ret += ".";
		//����С������
		unordered_map<long, int> umap;
		while (r)
		{
			if (umap.find(r) != umap.end())
			{
				int pos = umap[r];
				string s1 = ret.substr(0, pos);
				string s2 = ret.substr(pos, ret.size());
				ret = s1 + "(" + s2 + ")";
				break;
			}

			umap[r] = ret.size(); // ��¼������λ��

			r *= 10;
			ret += to_string(r / d);
			r = r % d;
		}

		return ret;
	}

	//�ο��� 0-ms
	//https://discuss.leetcode.com/topic/50057/0ms-17-lines-readable-c-solution
	string fractionToDecimal1(int numerator, int denominator)
	{
		if (!numerator)
			return "0";
		string ret;
		long long num = llabs(numerator), deno = llabs(denominator);
		if (numerator < 0 ^ denominator < 0)
			ret += '-';
		ret += to_string(num / deno);
		num = num % deno;
		if (!num)
			return ret;
		unordered_map<int, int> umap;
		ret += '.';
		while (!umap.count(num))
		{
			umap[num] = ret.size();
			while ((num *= 10) < deno)
			{
				ret += '0';
				umap[num] = ret.size();
			}
			ret += '0' + num / deno;
			if (!(num = num%deno))
				return ret;
		}
		ret.insert(umap[num], 1, '(');
		ret.insert(ret.size(), 1, ')');

		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.fractionToDecimal1(1, 6) << endl;
	cout << sol.fractionToDecimal1(2, 1) << endl;
	cout << sol.fractionToDecimal1(1, 3) << endl;
	cout << sol.fractionToDecimal1(2, 7) << endl;
}

int main()
{
	test();

	return 0;
}