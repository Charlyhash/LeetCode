/*
leetcode 26. Remove Duplicates from Sorted Array
��Ŀ���⣺���ڸ������������飬��ȥ���������ʹ��ÿ������ֻ����һ�Σ�����������ĳ���
����˼·������ÿһ���ַ����������ַ�����һ���ַ�һ���Ļ����ͼ����������һ���������1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
	{
		int ret = 1;
		if (nums.size() == 0)
			return 0;
		for (size_t i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != nums[i - 1])
				nums[ret++] = nums[i];			//Ҫ����Щ����������
		}

		return ret;
	}
};

void test_removeDuplicates()
{
	vector<int> vInt{1,1,2,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,8,9,9,9,9,9};
	Solution sol;
	cout << sol.removeDuplicates(vInt) << endl;
}

int main()
{
	test_removeDuplicates();
	return 0;
}