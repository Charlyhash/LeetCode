/*
leetcode 435. Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need 
to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

����˼·:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct {
	bool operator()(Interval& a, Interval& b)
	{
		return a.start < b.start;
	}
}cmp;

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) 
	{
		int len = intervals.size();
		if (!len)
			return 0;
		int res = 0;
		//������
		sort(intervals.begin(), intervals.end(), cmp);

		//for (auto inter : intervals)
		//{
		//	cout << inter.start << "," << inter.end << endl;
		//}

		//��һ�η��ʵĽڵ�
		int last = 0;
		for (int i = 1; i < len; ++i)
		{
			//������ڵ�start����һ�η��ʵĽڵ�end��ҪС��˵�����ظ�
			if (intervals[i].start < intervals[last].end)
			{
				++res;
				//̰��ѡ������Ҫ����С��ɾ����Ŀ�����ǿ϶���ɾ��endֵ��Ľڵ�
				//��������ǰ�ڵ�endֵ���ϸ��ڵ�endֵС�Ļ���ɾ���ϸ��ڵ㣬�������ڵ�
				//��last = i
				if (intervals[i].end < intervals[last].end)
					last = i;
			}
			else
				last = i;
		}

		return res;
	}
};

void TEST()
{
	Solution sol;
	vector<Interval> v{ Interval(1,2), Interval(2,3), Interval(2,3), Interval(3,4), Interval(3,4) };
	int ret = sol.eraseOverlapIntervals(v);
	cout << ret << endl;
}

int main()
{
	TEST();

	return 0;
}