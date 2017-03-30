/*
leetcode 282. Expression Add Operators
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

����˼·��

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

	//num:Ҫ������ַ�����target:Ҫ�����ֵ��diff:��ǰһ�μ���Ĳ���,�����г˷������
	//curNum:������μ����õ��Ľ����out��һ���ɹ��ļ�����ʽ��res:���ļ�����
	void dfs(string num, int target, long long diff, long long curNum, string out, vector<string>& res)
	{
		if (num.size() == 0 && curNum == target)
			res.push_back(out);
		for (int i = 1; i <= num.size(); ++i)
		{
			string cur = num.substr(0, i);
			if (cur.size() > 1 && cur[0] == '0')  //����0*������ʽ
				return;	
			string next = num.substr(i);
			if (out.size() > 0)
			{
				//�ӷ���������������stoll(cur),��ôdiffΪstoll(cur),���ε���+���ɹ�ʱ��Ҫ�ع���ԭ������
				dfs(next, target, stoll(cur), curNum+stoll(cur), out + '+'+cur, res);
				dfs(next, target, -stoll(cur), curNum-stoll(cur), out+'-'+cur, res);
				//�˷�����������ε�diffΪ��diff*stoll(cur)
				//���ε�curNumΪ����һ�ε�curNum-diff(����һ�λع�)Ȼ�����diff*stoll(cur)
				dfs(next, target, diff*stoll(cur), (curNum-diff)+diff*stoll(cur), out+'*'+cur, res);
			}
			else
			{
				//��һ����
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