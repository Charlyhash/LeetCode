/*
leetcode 303. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i �� j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

����˼·��
��һ������dp����nums�ĺͣ�dp[i]��ʾnums[0...i]�ĺ�
��sumRange(i,j)��Ϊdp[j]-dp[i-1];ע��߽�
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NumArray {

private: vector<int> dp;
public:
	NumArray(vector<int> &nums) 
	{
		if (nums.size() == 0)
			return;
		dp.push_back(nums[0]);
		for (int i = 1; i < nums.size(); ++i)
		{
			dp.push_back(dp[i - 1] + nums[i]);
			//cout << dp[i] << endl;
		}
	}

	int sumRange(int i, int j) 
	{
		if (i == 0)
			return dp[j];
		return dp[j] - dp[i-1];
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

void test()
{
	vector<int> nums{ -2, 0, 3, -5, 2, -1 };
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 1) << endl;
	cout << numArray.sumRange(1, 2) << endl;

}

int main()
{
	test();

	return 0;
}