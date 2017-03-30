/*
28. Implement strStr()
Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	//brute force approach
	int strStr(string haystack, string needle)
	{
		if (needle == "" && haystack == "")
			return 0;
		if (haystack == "" && needle != "")
			return -1;

		size_t len1 = haystack.length();
		size_t len2 = needle.length();
		if (len1 < len2)
			return -1;
		for (int i = 0; i <= len1 - len2; ++i)
		{
			for (int j = 0; j < len2&&haystack[i + j] == needle[j]; ++j)
			{
				if (j == len2 - 1)
					return i;
			}
		}
		return -1;
	}

	//Rabin¨CKarp algorithmËã·¨ - Hash ²éÕÒ
	int strStr(string haystack, string needle)
	{

	}
};

void test_strStr()
{
	Solution sol;
	cout << sol.strStr("b", "b") << endl;
}

int main()
{
	test_strStr();

	return 0;
}