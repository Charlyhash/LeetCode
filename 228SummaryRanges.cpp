/*
leetcode 228. Summary Ranges
��Ŀ���⣺���ڸ�������������(���ظ�Ԫ��)������Ԫ�ط�Χ
Ʃ��˵��[0,1,2,4,5,7]������["0->2","4->5","7"]
����˼·��
1��ȷ����Χ�����nums[end+1]==nums[end]+1,˵��������һ������
����Ļ�����ȷ����һ�����ء�
2����ʽ�����дһ������ֱ�������
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string format(int begin, int end)
	{
		char buffer[32];
		if (end == begin)
			sprintf(buffer, "%d", begin);
		else
			sprintf(buffer, "%d->%d", begin, end);

		return string(buffer);
	}
	vector<string> summaryRanges(vector<int>& nums) 
	{
		vector<string> result;
		if (nums.size() == 0)
			return result;
		int begin, end;
		begin = end= nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == end + 1)
			{
				end = nums[i];
			}
			else
			{
				result.push_back(format(begin, end));
				begin = end = nums[i];
			}
		}

		result.push_back(format(begin, end));

		return result;
		
	}
};

void test_summaryRanges()
{
	Solution sol;
	vector<int> nums{0,1,2,4,5,7};
	vector<string> vecString = sol.summaryRanges(nums);
	for (auto s : vecString)
		cout << s << " ";
	cout << endl;
}

int main()
{
	test_summaryRanges();

	return 0;
}
