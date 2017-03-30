/*
leetcode 067 Add Binary
��Ŀ�����������������Ƶ�����ӣ��õ���һ�������Ƶ��������еĶ������������ַ�����ʽ
����˼·���൱��Ҫ�Լ�ʵ�ּӷ��������λ��ʼ�ӣ����ǽ�λ�����⡣
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a == "" && b == "")
			return "";
		string ret;
		int carry = 0;
		size_t len1 = a.length();
		size_t len2 = b.length();
		for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; --i, --j)
		{
			carry += i >= 0 ? a[i]-'0' : 0;
			carry += j >= 0 ? b[j]-'0' : 0;
			ret = char(carry % 2 + '0') + ret;
			carry /= 2;
		}
		if (carry)
			ret = char(carry + '0') + ret;

		return ret;
	}
};


void test_addBinary()
{
	Solution sol;
	cout << sol.addBinary("11", "1") << endl;
	cout << sol.addBinary("11", "1111") << endl;
	cout << sol.addBinary("11", "0") << endl;

}
int main()
{
	test_addBinary();
	return 0;
}