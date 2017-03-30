/*
leetocde 93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid
IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

解题思路：

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
	vector<string> restoreIpAddresses(string s) 
	{
		vector<string> ret;
		if (s.size() < 4 || s.size() > 12)
			return ret;
		DFS(ret, s, "", 0);

		return ret;
	}

	void DFS(vector<string>& ret, string s, string tmp, int count)
	{
		//剪
		if (count > 4)
			return;
		if (s.size() < 4-count || s.size() > 3*(4-count))
			return;
		if (count == 3 && valid(s))
		{
			ret.push_back(tmp + s);
			return;
		}

		for (int i = 1; i < 4 && i < s.size(); ++i)
		{
			string str = s.substr(0, i);
			if (valid(str))
			{
				DFS(ret, s.substr(i), tmp + str + ".", count + 1);
			}
		}
	}

	bool valid(string s)
	{
		if (s[0] == '0' && s.size() > 1)
			return false;
		if (s.size() > 3)
			return false;
		if (s.size() == 3)
			return (s <= "255");
		return true;
	}

}; 

void TEST()
{
	Solution sol;
	vector<string> ret = sol.restoreIpAddresses("22522511135");
	for (auto s : ret)
		cout << s << endl;
} 

int main()
{
	TEST();

	return 0;
}