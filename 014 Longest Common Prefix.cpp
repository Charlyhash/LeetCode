/*
leetcode 14. Longest Common Prefix
解题思路：
找出每两个字符之间的公共前缀，然后让这个公共前缀为一个字符与后面的比较

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.size() == 0)
			return "";
		string ret = strs[0];		//prefix,先设定为第一个字符，然后与后面的每一个字符比较，找公共前缀
		int len;
		for (int i = 1; i < strs.size(); ++i)
		{
			len = ret.size() < strs[i].size() ? ret.size() : strs[i].size();
			if (len == 0)
				return "";
			int index= 0;			//前缀匹配的长度
			for (; index < len; ++index)
				if (ret[index] != strs[i][index])
					break;
			ret = ret.substr(0, index);
			/*
			substr的原型为：substr（size_type off,size_type count)
			off为string中的偏移量，count为截取的字符串的个数
			*/
			//cout << ret << endl;
		}

		return ret;
	}
};

void test_longestCommonPrefix()
{
	Solution sol;
	vector<string> vstr{ "abcdefg", "abcdefghij", "abcde", "abcd" };

	sol.longestCommonPrefix(vstr);
}

int main()
{
	test_longestCommonPrefix();
	return 0;
}