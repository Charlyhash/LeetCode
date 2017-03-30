/*
leetcode 165. Compare Version Numbers
先解析version然后比较
解析过程：通过字符'.'隔开，对每一个字符检查，如果为'.'，那么就可以压栈。
到最后访问完字符后也要压栈。
比较过程：从前面往后比较，对于"1", "1.1"这种也要考虑到，也就是说两个vector可能长度
不一样。对于不一样的情况，直接补0就行了。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1, v2;
		GetNumber(version1, v1);
		GetNumber(version2, v2);
		size_t len1 = v1.size();
		size_t len2 = v2.size();
		size_t num1, num2;
		for (size_t i = 0, j = 0; i < len1 || j < len2; ++i, ++j)
		{
			num1 = i < len1 ? v1[i] : 0;
			num2 = j < len2 ? v2[j] : 0;
			if (num1 > num2)
				return 1;
			if (num1 < num2)
				return -1;
		}
		return 0;
	}

	public:
	void GetNumber(string v, vector<int>& v1)
	{
		if (v.size() == 0)
			return;
		int sum=0;
		for (size_t i = 0; i < v.size(); ++i)
		{
		//遇到'.'就要压栈，到最后判断完后也要压栈
			if (v[i] == '.')
			{
				v1.push_back(sum);
				sum = 0;
			}
			else
			{
				sum = sum * 10 + v[i] - '0';
			}
		}
		v1.push_back(sum);
	}
};

void test_GetNumber()
{
	Solution sol;
	string version = "12.34.56";
	vector<int> v;
	sol.GetNumber(version, v);
	
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

void test_compareVersion()
{
	Solution sol;
	cout << sol.compareVersion("1.0.1", "1.0.0") << endl;
	cout << sol.compareVersion("11.34.44", "11.34.44") << endl;
	cout << sol.compareVersion("11.34.41", "11.34.42") << endl;
	cout << sol.compareVersion("1", "1.1") << endl;

}

int main()
{
	//test_GetNumber();
	test_compareVersion();
	return 0;
}