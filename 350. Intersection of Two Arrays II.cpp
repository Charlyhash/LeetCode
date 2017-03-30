/*
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

��Ŀ���⣺����������Ľ�����
����˼·��
����1��������Ȼ�����󽻼���������ֱ��ɨ���������飬����ȵ����ŵ�ret�м��ɡ�
����2��ʹ��unordered_map<key,value>��keyΪ��һ�������е����֣�valueΪ���ֵĴ������������һ�������г����˵Ļ����ͼ��뵽ret�С�

����1������Ѿ������ˣ���ô���÷���1
����2�����nums1��С����������������˵����飬��ô�൱����nums2�в���nums1��Ԫ�أ����Զ��ֲ��ҡ�
����3�����nums2�����ݺܴ�Ļ��������÷��εķ�����һ����һ�����ݡ�
*/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

		vector<int> ret;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int len1 = nums1.size();
		int len2 = nums2.size();
		int i = 0;
		int j = 0;
		while (i < len1 && j < len2)
		{
			if (nums1[i] == nums2[j])
			{
				ret.push_back(nums1[i]);
				++i;
				++j;
			}
			else
				nums1[i] > nums2[j] ? ++j : ++i;
		}
		return ret;
	}

	vector<int> intersect1(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> ret;
		if (nums1.size() == 0 || nums2.size() == 0)
			return ret;
		unordered_map<int, int> map;
		for (auto i : nums1)
			map[i]++;

		for (auto i : nums2)
			if (map[i]-- > 0)
				ret.push_back(i);

		return ret;
	}
};

void test()
{
	Solution sol;
	vector<int> nums1{ 1,2,3 };
	vector<int> nums2{1,2,4,5};
	vector<int> ret = sol.intersect1(nums1, nums2);
	//vector<int> ret = sol.intersect(nums1, nums2);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test();

	return 0;
}