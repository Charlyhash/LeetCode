/*
leetcode 409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters,
find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

题目大意：对于给定的字符串，用这些字符能组成的最长回文是多长。
解题思路：
最长回文长度计算方法：如果出现偶数次，则直接加上；如果出现奇数次，第一个基数加上奇数次，后面的基数只能取奇数次-1.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return len;
		vector<int> v(128, 0);

		for (int i = 0; i < len; ++i)
			++v[s[i]];

		int ret = 0;
		int oddNum = 0;
		for (int i = 0; i < 128; ++i)
		{
			if (v[i] & 0x01)
			{
				++oddNum;
			}

			ret += v[i];
		}
		if (oddNum)
			ret -= (--oddNum);

		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
}

int main()
{
	test();

	return 0;
}