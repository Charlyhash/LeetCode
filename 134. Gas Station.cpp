/*
leetcode 134. Gas Station

There are N gas stations along a circular route, where the amount 
of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of 
gas to travel from station i to its next station (i+1). You begin 
the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around 
the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

解题思路：
从第一个油站出发：remain = gas[0]-cost[0];到第i个油站remain += gas[i]-cost[i]
有以下几种情况：
(1) remain >= 0,因此可以到下一个油站，继续走；
(2) remain < 0,不能往下走。既然如此，说明从[0...i]都不能到达i+1个油站,直接从i+1个
油站出发(贪心所在)
那么如何判断可以走完呢？如果总油量>=总耗费量，一定是可以走完的
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int len = gas.size();
		int start = 0;
		int remain = 0;
		int totalGas = 0; int totalCost = 0;
		for (int i = 0; i < len; ++i)
		{
			totalGas += gas[i]; totalCost += cost[i];
			remain += gas[i] - cost[i];

			if (remain < 0)
			{
				start = i + 1;
				remain = 0;
			}
		}

		if (totalCost <= totalGas)
			return start;

		return -1;
	}
};

void  TEST()
{
	vector<int> cost{ 1,5,2,3,4 };
	vector<int> gas{ 1,2,3,5,6 };
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;


}

int main()
{
	TEST();

	return 0;
}