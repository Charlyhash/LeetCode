/*
leetcode 315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

	Given nums = [5, 2, 6, 1]

	To the right of 5 there are 2 smaller elements (2 and 1).
	To the right of 2 there is only 1 smaller element (1).
	To the right of 6 there is 1 smaller To (1).
	element the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0].

��Ŀ���⣺����һ�����飬����һ����ͬ��С�����飬������ÿ��λ�õ�Ԫ��Ϊԭ�����к���С�ڸ�Ԫ�صĸ�����
����˼·��
(1)�������Ƚ�(TLE)
(2)��������������飬ͬʱά��һ�����飬ÿ�δ�����������ҵ���һ�����ڵ�ǰԪ�ص�λ������ұ��ж��ٸ�����С������
ʱ�临�Ӷ�ΪO(n^2)
(3)��(2)�ĸĽ�������ʱ�ö��ֵķ���

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//TLE
	vector<int> countSmaller(vector<int>& nums) 
	{
		int len = nums.size();
		if (len == 0)
			return nums;
		vector<int> ret(len, 0);
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (nums[i] > nums[j])
					++ret[i];
			}
		}

		return ret;
	}
	//ά��һ�����飬�Ǳ�������nums�е�һ�����������
	vector<int> countSmaller1(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0)
			return nums;
		vector<int> v;//ά��������
		vector<int> ret(len, 0);
		for (int i  = len - 1; i >= 0; --i)
		{
			
			auto iter = lower_bound(v.begin(), v.end(), nums[i]);
			ret[i] = iter - v.begin();
			v.insert(iter, nums[i]);
		}

		return ret;
	}
	
	vector<int> countSmaller2(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0)
			return nums;
		vector<int> v;//ά��������
		vector<int> ret(len, 0);

		
		for (int i = len - 1; i >= 0; --i)
		{
			if (v.empty())
			{
				ret[i] = 0;
				v.push_back(nums[i]);
			}
			else
			{
				//���ֲ���:�ҵ���nums[i]
				int l = 0, r = v.size() - 1;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (v[mid] < nums[i])
						l = mid + 1;
					else
						r = mid - 1;
				}
				v.insert(v.begin() + l, nums[i]);
				ret[i] = l;
			}
			
		}

		return ret;
	}
};

//BST
//���ֲ��ң�ά��һ��
class Solution1 {
public:
	//node
	typedef struct Node {
		int val, smaller;//the current node value and the count smaller then val int the child
		struct Node* left, *right;
		Node(int v, int s) : val(v), smaller(s), left(NULL),right(NULL){}
	}node;

	int insert(node* &root, int v)
	{
		if (root == NULL) {
			root = new node(v, 0);
			return 0;
		}
		if (root->val > v) {
			root->smaller++;
			return insert(root->left, v);
		}
		else {
			return (insert(root->right, v) + root->smaller + (root->val < v ? 1: 0));
		}
	}

	vector<int> countSmaller(vector<int>& nums)
	{
		vector<int> ret(nums.size(), 0);
		node* root = NULL;
		for (int i = nums.size()-1;i >=0; --i) {
			ret[i] = insert(root, nums[i]);
			cout << ret[i] << " " << endl;
		}
		cout << endl;

		return ret;
	}
};

void test()
{
	vector<int> v{5,2,6,1};
	Solution sol;
	//vector<int> ret = sol.countSmaller(v);
	//vector<int> ret = sol.countSmaller1(v);
	vector<int> ret = sol.countSmaller2(v);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;


	Solution1 sol1;
	vector<int> ret1 = sol1.countSmaller(v);
	for (auto i : ret1)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test();

	return 0;
}