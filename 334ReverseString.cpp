/*leetcode 334 ----字符串翻转
	解题思路：把字符串第i个和第len-1-i个位置的字符交换即可。
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