/*
leetcode 282. Expression Add Operators
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

解题思路：

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target)
	{
		vector<string> res;
		dfs(num, target, 0, 0, "", res);
		return res;
	}

	//num:要计算的字符串；target:要计算的值；diff:和前一次计算的差异,用于有乘法的情况
	//curNum:经过这次计算后得到的结果，out：一个成功的计算表达式，res:最后的计算结果
	void dfs(string num, int target, long long diff, long long curNum, string out, vector<string>& res)
	{
		if (num.size() == 0 && curNum == target)
			res.push_back(out);
		for (int i = 1; i <= num.size(); ++i)
		{
			string cur = num.substr(0, i);
			if (cur.size() > 1 && cur[0] == '0')  //消除0*这种形式
				return;	
			string next = num.substr(i);
			if (out.size() > 0)
			{
				//加法的情况，如果加上stoll(cur),那么diff为stoll(cur),本次调用+不成功时，要回滚到原来的数
				dfs(next, target, stoll(cur), curNum+stoll(cur), out + '+'+cur, res);
				dfs(next, target, -stoll(cur), curNum-stoll(cur), out+'-'+cur, res);
				//乘法的情况：本次的diff为：diff*stoll(cur)
				//本次的curNum为：上一次的curNum-diff(这是一次回滚)然后加上diff*stoll(cur)
				dfs(next, target, diff*stoll(cur), (curNum-diff)+diff*stoll(cur), out+'*'+cur, res);
			}
			else
			{
				//第一个数
				dfs(next, target, stoll(cur), stoll(cur), cur, res);
			}
		}
	}
};

void test()
{
	string num{ "232" };
	int target = 8;
	Solution sol;
	vector<string> v;
	v = sol.addOperators(num, 8);
	for (auto s : v)
	{
		cout << s << " ";
	} 
	cout << endl;
}

int main()
{
	test();
	return 0;
}