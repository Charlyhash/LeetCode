/*
leetcode 17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
参考：http://www.cnblogs.com/ganganloveu/p/4175384.html
枚举所有情况
对于每一个输入数字，对于已有的排列中每一个字符串，分别加入该数字所代表的每一个字符。
所有是三重for循环。
举例：
初始化排列{""}
1、输入2，代表"abc"
已有排列中只有字符串""，所以得到{"a","b","c"}
2、输入3，代表"def"
(1)对于排列中的首元素"a"，删除"a"，并分别加入'd','e','f'，得到{"b","c","ad","ae","af"}
(2)对于排列中的首元素"b"，删除"b"，并分别加入'd','e','f'，得到{"c","ad","ae","af","bd","be","bf"}
(2)对于排列中的首元素"c"，删除"c"，并分别加入'd','e','f'，得到{"ad","ae","af","bd","be","bf","cd","ce","cf"}

参考 https://github.com/soulmachine/leetcode
递归求解

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
				string cur = ret[0];		//取出第一个string
				ret.erase(ret.begin());
				//对于数字对应的字母来说，和cur相加，然后加入到数组中
				for (size_t k = 0; k < letters[digits[i] - '0'].size(); ++k)
					ret.push_back(cur + letters[digits[i] - '0'][k]);
			}
		}

		return ret;
	}

	//递归解法
	//由于长度固定为digits.size(),那么每次到了这个长度就压入
	const vector<string> letters{ "", "", "abc", "def", "ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz" };
	//digits为数字，cur为当前path的长度，path为找到的组合，reslut为结果数组
	void dfs(const string& digits, size_t cur, string path, vector<string> result)
	{
		//当到了这个长度之后，说明path已经找到一个
		if (cur == digits.size())
		{
			result.push_back(path);
			return;
		}
		//如果没有，还要继续加入其他的字母。
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