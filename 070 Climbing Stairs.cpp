/*
70. Climbing Stairs  QuestionEditorial Solution  My Submissions
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

����˼·��
�����ߵ���n�׵����һ����������һ��������������ô��n�׵Ĳ������ڵ�n-1�ײ���+n-2�ײ�����
dp[n] = dp[n-1]+dp[n-2]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) 
	{
		vector<int> dp(n+1, 0);
		if (n < 3)
			return n;
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}
	
	int climbStairs1(int n)
	{
		if (n < 3)
			return n;
		int pre1 = 2;	//ǰһ��������(n-1)��step
		int pre2 = 1;	//n-2��step
		int ret = 0;
		int tmp = 0;
		for (int i = 3; i <= n; ++i)
		{
			ret = pre1 + pre2;
			//cout << ret << endl;
			tmp = pre1;	//����pre1��pre2
			pre1 = ret;
			pre2 = tmp;
		}
		//cout << "---------------" << endl;
		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.climbStairs1(10) << endl;
}

int main()
{
	test();

	return 0;
}