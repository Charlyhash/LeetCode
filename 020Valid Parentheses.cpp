/*
leetcode 20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
The brackets must close in the correct order,
"()" and "()[]{}" are all valid but "(]" and "([)]" are not

����˼·����һ��ջά��û��ƥ���ջ����ջ��Ԫ������һ���ַ�ƥ��ʱ��������Ԫ�أ�����ƥ�����
ջΪ��ʱ����ջ��������ջΪ�գ�˵��ȫ��ƥ���꣬�����Ϊ�գ�˵�������ַ�û��ƥ�䡣

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
            return true;
        if (s.size() & 0x01)
            return false;
		stack<char> c;
		int i = 0;
		while (i < s.size())
		{
			if (c.empty())
			{
				c.push(s[i]);
			}
			else
			{
				if ((c.top() == '(' && s[i] == ')') ||
					(c.top() == '[' && s[i] == ']') ||
					(c.top() == '{' && s[i] == '}'))
					c.pop();
				else
				{
					//cout << s[i] << endl;
					c.push(s[i]);
				}
			}
			++i;
		}

		return c.size() == 0;
    }
};

void TEST()
{
    Solution sol;
	string s{ "([)]" };
    string s1{"[][]{}{}()"};
    string s2{"[][]{{[]}}()()"};

    cout << sol.isValid(s) << endl;
    cout << sol.isValid(s2) << endl;
}

int main()
{
    TEST();
    return 0;
}


