/*
leetcode 300. Longest Increasing Subsequence
IMC�ⷨ
����˼·��
��������nums[] = [10, 9, 2, 5, 3, 7, 101, 18],��LIS
ά��һ������D[],D[1]=nums[0],��ʱLIS����һ��Ԫ��10������len=1��
���ں���������赱ǰLIS����Ϊlen:
1. nums[i] > D[len],����D[],len++,D[len] = nums[i]
2. ������D[1...len]���ҵ�һ������j,����D[j]<A[i],��ôD[j] < nums[i] <= D[j+1].D[j+1]=nums[i]
��ʱ��D[]Ϊ����Ǳ����LIS��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;
		vector<int> d(nums.size(), 0);
		int top = 0;		//���һ��Ԫ���±�
		d[0] = nums[0];
		for (size_t i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > d[top])
			{
				++top;
				d[top] = nums[i];
			}
			else
			{
				int pos = MyLowerBound(d, top + 1, nums[i]);
				d[pos] = nums[i];
			}
		}

		return top+1;
	}
	
	int MyLowerBound(vector<int> &v, int size, int key)
	{
		int left = 0;
		int right = size - 1;
		int mid;
		int pos = 0;//��¼��һ��>=key��Ԫ��λ��
		while (left < right)
		{
			mid = (left + right) / 2;
			if (v[mid] < key)    //v[mid]<key,���ұ߲���
			{
				left = mid + 1;
				pos = left;
			}
			else
			{
				right = mid;    //����߲��ң���Ϊmid�����ܾ���Ҫ�ҵ�λ�ã���˲���mid-1
				pos = right;
			}
		}

		return pos;
	}

};

void TEST_LIS()
{
	Solution sol;
	vector<int> v{ 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << sol.lengthOfLIS(v) << endl;
}


int main()
{
	TEST_LIS();

	return 0;
}