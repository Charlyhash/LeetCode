/*
leetcode 80. Remove Duplicates from Sorted Array II
��Ŀ���⣺������õ�������ɾ���ظ�Ԫ�أ���������ظ�����Ϊ2��
����˼·��������������飬����ظ���������2����ôһ����nums[i] == nums[i-2],����ǰ�������
Ʃ��˵��1��1��1��2��2��2��3��4��5������Ŵ�0��ʼ����2���͵�0����ȣ��ʶ�˵�����ظ�Ԫ�ء�
�ڶ�����ɨ��Ĺ����У�Ҫ��¼������ɾ������Ԫ�غ����ţ�������������Ϊ�������ţ�
����ɾ����Ԫ��ֱ�Ӹ��Ǿ����ˡ�
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search2(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target == nums[mid])
			return mid;

		if (nums[mid] < nums[right])
		{
			if (target > nums[mid] && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			if (nums[left] <= target && nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return -1;
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret = 2;
		if (nums.size() < 2)
			return nums.size();
		for (size_t i = 2; i < nums.size(); ++i)
		{
			if (nums[i] != nums[ret - 2])		//�ж��ظ��Ĵ����ǲ��Ǵ���2
				nums[ret++] = nums[i];			//ֱ�Ӹ��ǣ���ret��¼�µ�λ��
		}

		return ret;
	}
};

void test_removeDuplicates()
{
	Solution sol;
	vector<int> nums{ 1,1,1,2,2,2,2,2,3,3,4,5,6,6,6,7,7,8,9,10 };
	int ret = sol.removeDuplicates(nums);
	cout << ret << endl;
	for (int i = 0; i < ret; ++i)
		cout << nums[i] << " ";
	cout << endl;
}

int main()
{
	test_removeDuplicates();

	return 0;
}