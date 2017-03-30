/*
leetcode 17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
�ο���http://www.cnblogs.com/ganganloveu/p/4175384.html
ö���������
����ÿһ���������֣��������е�������ÿһ���ַ������ֱ����������������ÿһ���ַ���
����������forѭ����
������
��ʼ������{""}
1������2������"abc"
����������ֻ���ַ���""�����Եõ�{"a","b","c"}
2������3������"def"
(1)���������е���Ԫ��"a"��ɾ��"a"�����ֱ����'d','e','f'���õ�{"b","c","ad","ae","af"}
(2)���������е���Ԫ��"b"��ɾ��"b"�����ֱ����'d','e','f'���õ�{"c","ad","ae","af","bd","be","bf"}
(2)���������е���Ԫ��"c"��ɾ��"c"�����ֱ����'d','e','f'���õ�{"ad","ae","af","bd","be","bf","cd","ce","cf"}

�ο� https://github.com/soulmachine/leetcode
�ݹ����

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> ret;
		if (digits == "")
			return ret;
		ret.push_back("");

		vector<string> letters{ "", "", "abc", "def", "ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz" };
		for (size_t i = 0; i < digits.size(); ++i)
		{
			int size = ret.size();
			for (size_t j = 0; j < size; ++j)
			{
				string cur = ret[0];		//ȡ����һ��string
				ret.erase(ret.begin());
				//�������ֶ�Ӧ����ĸ��˵����cur��ӣ�Ȼ����뵽������
				for (size_t k = 0; k < letters[digits[i] - '0'].size(); ++k)
					ret.push_back(cur + letters[digits[i] - '0'][k]);
			}
		}

		return ret;
	}

	//�ݹ�ⷨ
	//���ڳ��ȹ̶�Ϊdigits.size(),��ôÿ�ε���������Ⱦ�ѹ��
	const vector<string> letters{ "", "", "abc", "def", "ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz" };
	//digitsΪ���֣�curΪ��ǰpath�ĳ��ȣ�pathΪ�ҵ�����ϣ�reslutΪ�������
	void dfs(const string& digits, size_t cur, string path, vector<string> result)
	{
		//�������������֮��˵��path�Ѿ��ҵ�һ��
		if (cur == digits.size())
		{
			result.push_back(path);
			return;
		}
		//���û�У���Ҫ����������������ĸ��
		for (auto c : letters[digits[cur] - '0'])
			dfs(digits, cur + 1, path + c, result);
	}

	vector<string> letterCombinations1(string digits)
	{
		vector<string> result;
		if (digits.empty())
			return result;
		dfs(digits, 0, "", result);
		return result;
	}
};

void TEST()
{
	Solution sol;
	vector<string> ret;
	vector<string> ret1;
	ret = sol.letterCombinations("23");
	ret1 = sol.letterCombinations1("23");
	for (auto c : ret)
		cout << c << " ";
	cout << endl;

	for (auto c : ret1)
		cout << c << " ";
	cout << endl;
}

int main()
{
	TEST();

	return 0;
}