/*
leetcode:

��Ŀ���⣺
��Դ��ţ����
��һ����������arr��һ����СΪw�Ĵ��ڴ����������߻������ұߣ�����
ÿ�����ұ߻�һ��λ�á�
���磬����Ϊ[4,3,5,4,3,3,6,7]�����ڴ�СΪ3ʱ��
[4 3 5] 4 3 3 6 7 ���������ֵΪ5
4 [3 5 4] 3 3 6 7 ���������ֵΪ5
4 3 [5 4 3] 3 6 7 ���������ֵΪ5
4 3 5 [4 3 3] 6 7 ���������ֵΪ4
4 3 5 4 [3 3 6] 7 ���������ֵΪ6
4 3 5 4 3 [3 6 7] ���������ֵΪ7

������鳤��Ϊn�����ڴ�СΪw����һ������n-w+1�����ڵ����ֵ����ʵ��һ��������
����һ������arr�����ڴ�Сw������һ������Ϊn-w+1������res,res[i]��ʾÿһ��
����״̬�µ����ֵ���Ա���Ϊ�������Ӧ�÷���[5,5,5,4,6,7]��

����˼·��
1.ֱ�ӱ�������ÿk�����е����ֵ��ʱ�临�Ӷ�ΪO(NK)
2.ά��һ��˫�˶��У��������汣���ʱ��ǰλ��֮ǰ�����ֵ���±꣬��ǰ�±��������
�򵯳�(=i-k).

*/

#include "Header.h"

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{
		vector<int> ret;
		if (nums.size() == 0)
			return ret;
		deque<int> qmax; //��¼��ǰ���ֵ��λ��
		for (int i = 0; i < nums.size(); ++i)
		{
			while (!qmax.empty() && nums[qmax.back()] < nums[i])
				qmax.pop_back();
			qmax.push_back(i);
			if (qmax.front() == i - k) //�ж��Ƿ����
				qmax.pop_front();
			if (i >= k - 1)
				ret.push_back(nums[qmax.front()]);
		}

		return ret;
	}

	//ö��
	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		vector<int> ret;
		if (nums.size() == 0)
			return ret;
		for (int i = 0; i <= nums.size() - k; ++i)
		{
			int tmp = nums[i];
			for (int j = 1; j < k; ++j)
				tmp = max(tmp, nums[i + j]);
			ret.push_back(tmp);
		}

		return ret;
	}
};

int main()
{
	vector<int> v{ 1,3,-1,-3,5,3,6,7 };
	Solution sol;
	vector<int> ret = sol.maxSlidingWindow(v, 3);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	return 0;
}