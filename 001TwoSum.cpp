/*
leetcode 001 TwoSum
��Ŀ���⣺�Ӹ�����һ�������ҵ��������ĺ�Ϊtarget.��������������ţ�����ÿ������ֻ��һ���
����˼·��
1����������������ÿ����ȥ�Һ�������ĺ�Ϊtarget����������ҵ��˾ͷ���
�Һ����һ���ύ�ñ���������Ȼ���ˡ�
2��hash���Ƚ���hashӳ�䣬<key,value>Ϊ <nums[i], i>������ÿһ������������O(1)��ʱ���ҵ�
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//��������
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> index;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = i+1; j < nums.size(); ++j)
			{
				if ((nums[i] + nums[j]) == target)
				{
					index.push_back(i);
					index.push_back(j);
					return index;
				}
			}
		}
	}

	//hash
	vector<int> twoSum1(vector<int>& nums, int target)
	{
		unordered_map<int, int> mapping;			//hash map
		vector<int> result;							//result
		for (size_t i = 0; i < nums.size(); ++i)	//O(n)������hash
		{
			mapping[nums[i]] = i;
		}
		for (size_t i = 0; i < nums.size(); ++i)
		{
			const int gap = target - nums[i];							//�ҵ������
			if (mapping.find(gap) != mapping.end() && mapping[gap]!=i)	//�ҵ��ˣ�O(1)
			{
				result.push_back(i + 1);								//index 1
				result.push_back(mapping[gap] + 1);						//index 2
				break;
			}
		}
		return result;
	}
};

void test_twoSum()
{
	Solution sol;
	vector<int> index;
	vector<int> nums{4,71,15,3,9,17,13,25,1,33,0};
	int target = 30;
	index = sol.twoSum(nums, target);
	//���
	for (auto i : index)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test_twoSum1()
{
	Solution sol;
	vector<int> index;
	vector<int> nums{ 4,71,15,3,9,17,13,25,1,33,0 };
	int target = 30;
	index = sol.twoSum1(nums, target);
	//���
	for (auto i : index)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	test_twoSum();
	
	return 0;
}
