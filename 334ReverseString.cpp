/*leetcode 334 ----�ַ�����ת
	����˼·�����ַ�����i���͵�len-1-i��λ�õ��ַ��������ɡ�
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int len = s.length();
		if (len==0 || len == 1)
			return s;
		char c;
		
		for (int i = 0; i < len / 2; ++i)
		{
			c = s[i];
			s[i] = s[len - 1 - i];
			s[len - 1 - i] = c;
		}

		return s;
	}
};

int main()
{
	Solution sol;
	string s("abcdefg");
	cout << sol.reverseString(s) << endl;

	return 0;
}