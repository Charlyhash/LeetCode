/*
leetcode 66. Plus One
��Ŀ���⣺����һ���Ǹ��������洢�������У���������ּ�1������������λ����ǰ�档
����˼·���������������λΪС��9��ֱ�Ӽӵ����λȥ
�������������λΪ9��Ϊ2�������
1��û�е����λ��Ҳ����digits[0]��,����һλΪ0��Ȼ�������һλ�������Ҳ�Ǽ�1
2������������λ��˵���ˣ�������Ǻܶ�9����Ȼ��1��ô���ܻ�������λ�أ���������ΪΪ1
Ȼ��ѹ��һ��0.
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
			//����С��9���������һ��ֱ�ӷ���
			if (digits[i] < 9)
			{
				++digits[i];
				return digits;
			}
			else  //�������9�����
			{
				if (i != 0)		//û�е����λ
					digits[i] = 0;
				else			//�������λ��
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