/*
leetcode 349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
题目大意：求交集，求出来的交集中每个元素只有一个
方法1：用两个map存储nums[i],true.然后再将两个map中相同的数加入到数组中。
方法2：其他方法1用一个map就行了。在判断第二个数组中的数在map中后需要判断
value是否为true，如果为true，加入返回数组后，设为false,这样下次遇到同样
的数的时候就不会再次加入到返回数组中了。
方法3:先sort然后求交集，最后用unique函数
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