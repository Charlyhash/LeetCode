/*
leetcode 349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
��Ŀ���⣺�󽻼���������Ľ�����ÿ��Ԫ��ֻ��һ��
����1��������map�洢nums[i],true.Ȼ���ٽ�����map����ͬ�������뵽�����С�
����2����������1��һ��map�����ˡ����жϵڶ��������е�����map�к���Ҫ�ж�
value�Ƿ�Ϊtrue�����Ϊtrue�����뷵���������Ϊfalse,�����´�����ͬ��
������ʱ��Ͳ����ٴμ��뵽�����������ˡ�
����3:��sortȻ���󽻼��������unique����
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> nmap1;
		unordered_map<int, bool> nmap2;
		vector<int> ret;
		for (auto i : nums1)
			nmap1.insert({i, true});
		for (auto i : nums2)
			nmap2.insert({ i, true });
		for (auto iter = nmap1.begin(); iter != nmap1.end(); iter++)
			if (nmap2.find(iter->first) != nmap2.end())
				ret.push_back(iter->first);

		return ret;
	}

	vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> nmap;
		vector<int> ret;
		for (auto i : nums1)
			nmap.insert({i, true});
		for (auto i : nums2)
		{
			if (nmap.find(i) != nmap.end())
			{
				if (nmap[i])
				{
					ret.push_back(i);
					nmap[i] = false;
				}
			}
		}

		return ret;
	}

	vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> v(nums1.size() + nums2.size());
		auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());

		v.resize(it - v.begin());

		vector<int> v2(v.begin(), unique(v.begin(), v.end()));

		return v2;
	}


};

void test()
{
	
}

int main()
{
	test();

	return 0;
}