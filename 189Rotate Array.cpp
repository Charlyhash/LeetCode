/*
leetcode 189. Rotate Array
题目大意：
Rotate an array of n elements to the right by k steps.
譬如说对于k=3,[1,2,3,4,5,6,7]旋转为[5,6,7,1,2,3,4].
解题思路：用一个临时的数组，然后根据k的值,旋转临时数组，然后复制到原来的数组

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//方法1：使用临时数组，先复制后k个元素，再负责n-7个元素
	void rotate(vector<int>& nums, int k) 
	{
		int n = nums.size();
		k = k % n;
		if (n <= 1 || k == 0)
			return;
		
		vector<int> tmp;
		
		for (int i = n -k ; i < n; ++i)
			tmp.push_back(nums[i]);
		for (int i = 0;i < n-k; ++i)
			tmp.push_back(nums[i]);

		nums = tmp;
	}

	//方法2：直接使用vector的函数
	void rotate2(vector<int>& nums, int k)
	{
		int n = nums.size();
		k = k % n;
		if (n <= 1 || k == 0)
			return;

		vector<int> extra(nums.begin(), nums.begin() + n - k);
		//for (auto i : extra)
		//	cout << i << " ";
		//cout << endl;
		nums.erase(nums.begin(), nums.begin()+n-k);
		//for (auto i : nums)
		//	cout << i << " ";
		//cout << endl;
		nums.insert(nums.end(), extra.begin(), extra.end());
	}
};

void test_rotate()
{
	vector<int> nums{ 1, 2 ,3, 4, 5, 6, 7};
	Solution sol;
	sol.rotate(nums, 3);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
}

void test_rotate2()
{
	vector<int> nums{ 1, 2 ,3, 4, 5, 6, 7 };
	Solution sol;
	sol.rotate2(nums, 3);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
}

int main()
{
	//test_rotate();
	test_rotate2();
	return 0;
}