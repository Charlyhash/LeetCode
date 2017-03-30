/*
leetcode 20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
The brackets must close in the correct order,
"()" and "()[]{}" are all valid but "(]" and "([)]" are not

解题思路：用一个栈维护没有匹配的栈，当栈顶元素与下一个字符匹配时，弹出该元素，当不匹配或者
栈为空时，入栈。最后如果栈为空，说明全部匹配完，如果不为空，说明还有字符没有匹配。

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


