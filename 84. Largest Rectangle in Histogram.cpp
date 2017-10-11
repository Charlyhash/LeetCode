/*
leetcode 84. Largest Rectangle in Histogram
��Ŀ���⣺
���ڸ�����n���Ǹ�����������ֱ��ͼ�ĸ߶ȣ����Ϊ1����ֱ��ͼ���ҳ��������ľ���

����˼·��
��Ҫ�ҵ�ÿ�����������������չ�����٣����ҵ����Ҹպñȵ�ǰ�߶�С��λ�ã���ջ��ʵ��
ʹ��һ��ջ������h���飬ÿ����һ��λ�ã������λ�õ�ֵi��ջ����Ӧλ�õ�ֵ����ôֱ����ջ��
����ջ��Ԫ��j��ջ���µ�ջ��Ϊk(Ϊ����Ϊ-1)����˵����jλ�õ�Ԫ�أ���߸պñ���С��ʱkλ�ã�
�ұ߸պñ���С����iλ��,������Ϊh[i]*(k-j-1)��
������ջ��Ϊ�գ����Լ�����һ���߶Ⱥ�С��ֵ����ô���еĶ�Ҫ��ջ���������
*/
#include "Header.h"

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) 
	{
		int n = heights.size();
		if (n == 0)
			return 0;

		stack<int> s;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			while (!s.empty() && heights[i] <= heights[s.top()])
			{
				int j = s.top();
				s.pop();
				int k = s.empty() ? -1 : s.top();
				int curArea = (i - k - 1)* heights[j];
				ret = max(ret, curArea);
			}
			s.push(i);
		}
		while (!s.empty())
		{
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (n - k - 1)* heights[j];
			ret = max(ret, curArea);
		}

		return ret;
	}
};

int main()
{

	vector<int> v{2,1,5,6,2,3};
	Solution sol;
	cout << sol.largestRectangleArea(v) << endl;

	return 0;
}
