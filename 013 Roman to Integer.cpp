/*
leetcode:13. Roman to Integer
��������תΪ����
����������һ�¼���
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000
��������
1����ͬ��������д������ʾ����������Щ������ӵõ������� ��XXX����ʾ����10*3=30
2��С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ���������CL��150
3��С�����֣����� ��X �� C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ���������XL��40
4����һ���������滭һ�����ߣ���ʾ�������ֵ 1,000 ������V(�ϻ���)��50000
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) 
	{
		int len = s.length();
		if (len == 0)
			return 0;
		map <char, int> r;
		r['I'] = 1;
		r['V'] = 5;
		r['X'] = 10;
		r['L'] = 50;
		r['C'] = 100;
		r['D'] = 500;
		r['M'] = 1000;

		int i = len - 1;
		int ret = r[s[i]];
		--i;
		while (i >= 0)
		{
			//����������ұߵ����ֱȽ�
			if (r[s[i]] < r[s[i + 1]])		//��������ұߵ���С��Ҫ��������IV,Ϊ5-1;
				ret -= r[s[i--]];
			else							//��������ұߵ����������ȣ�Ҫ�ӣ���VII��Ϊ5+1+1
				ret += r[s[i--]];			
		}

		return ret;
	}
};

void test_romanToInt()
{
	Solution sol;
	cout << "���ַ� = " << sol.romanToInt("") << endl;
	cout << "X = " << sol.romanToInt("X") << endl;
	cout << "MCMLXXX = " << sol.romanToInt("MCMLXXX") << endl;
	cout << "III = " << sol.romanToInt("III") << endl;
	cout << "IV = " << sol.romanToInt("IV") << endl;
	cout << "VI = " << sol.romanToInt("VI") << endl;
	cout << "XIX = " << sol.romanToInt("XIX") << endl;
	cout << "XX = " << sol.romanToInt("XX") << endl;
	cout << "XLV = " << sol.romanToInt("XLV") << endl;
}
int main()
{
	test_romanToInt();

	return 0;
}
/*
���ַ� = 0
X = 10
MCMLXXX = 1980
III = 3
IV = 4
VI = 6
XIX = 19
XX = 20
XLV = 45
*/

