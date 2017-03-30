/*
leetcode 241. Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

����˼·�����Σ�����һ�������,�ͼ������ߵĽ����Ȼ������п��ܵĽ���������㣬ѹ��vector��

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) 
	{
		vector<int> res;
		int size = input.size();
		for (size_t i = 0; i < size; ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				vector<int> tmp1 = diffWaysToCompute(input.substr(0, i));
				vector<int> tmp2 = diffWaysToCompute(input.substr(i + 1));
				for (auto n1 : tmp1)
				{
					for (auto n2 : tmp2)
					{
						if (input[i] == '+')
							res.push_back(n1 + n2);
						else if (input[i] == '-')
							res.push_back(n1 - n2);
						else
							res.push_back(n1*n2);
					}
				}
			}
		}

		//���Ϊ�գ�˵��û��������ţ���һ������
		if (res.empty())
			res.push_back(atoi(input.c_str()));

		return res;
	}
};

void test()
{
	Solution sol;
	auto res = sol.diffWaysToCompute("2*3-4*5");
	for (auto i : res)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test();

	return 0;
}