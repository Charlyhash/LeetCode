/*
leetcode 263. Ugly Number
��Ŀ���⣺���һ�����Ƿ�ΪUgly Number(ֻ��2��3��5�⼸����������)��1Ҳ��
Ʃ��˵6=2*3��12=2*2*3�����6��12����Ugly Number;14=2*7�Ͳ���Ugly Number
����˼·������һ����num,�����2�ı�����һֱ����2����3�ı�����һֱ����3����
5�ı�����һֱ����5.����֮�����Ϊ1����˵����Ugly Number,����ͻ�������������
���ӣ�����Ugly Number.
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