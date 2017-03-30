/*
leetcode 189. Rotate Array
��Ŀ���⣺
Rotate an array of n elements to the right by k steps.
Ʃ��˵����k=3,[1,2,3,4,5,6,7]��תΪ[5,6,7,1,2,3,4].
����˼·����һ����ʱ�����飬Ȼ�����k��ֵ,��ת��ʱ���飬Ȼ���Ƶ�ԭ��������

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//����1��ʹ����ʱ���飬�ȸ��ƺ�k��Ԫ�أ��ٸ���n-7��Ԫ��
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

	//����2��ֱ��ʹ��vector�ĺ���
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