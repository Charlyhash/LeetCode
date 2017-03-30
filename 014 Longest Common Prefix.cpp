/*
leetcode 14. Longest Common Prefix
����˼·��
�ҳ�ÿ�����ַ�֮��Ĺ���ǰ׺��Ȼ�����������ǰ׺Ϊһ���ַ������ıȽ�

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
		string ret = strs[0];		//prefix,���趨Ϊ��һ���ַ���Ȼ��������ÿһ���ַ��Ƚϣ��ҹ���ǰ׺
		int len;
		for (int i = 1; i < strs.size(); ++i)
		{
			len = ret.size() < strs[i].size() ? ret.size() : strs[i].size();
			if (len == 0)
				return "";
			int index= 0;			//ǰ׺ƥ��ĳ���
			for (; index < len; ++index)
				if (ret[index] != strs[i][index])
					break;
			ret = ret.substr(0, index);
			/*
			substr��ԭ��Ϊ��substr��size_type off,size_type count)
			offΪstring�е�ƫ������countΪ��ȡ���ַ����ĸ���
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