/*
leetcode 4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
参考：https://github.com/soulmachine/leetcode
在两个排序的数组中找到中位数
时间复杂度要求为O(log(m+n))
解题思路：
求第k大的元素的方法
1、直接合并两个数组，然后求第k大的数。时间复杂度为O(m+n)
2、用两个指针，pa和pb,分别指向A，B两个数组的第一个元素。如果A中元素小，pa++, m++;
如果B中元素小，pb++,m++。当m==k时，我们就找到了这个元素.时间复杂度为O(k)
3、从k入手，如果能一次删除一半在k之前的元素，复杂度应该能达到要求
先假设A和B中的元素都大于k/2,将A[k/2-1]与B[k/2-1]比较（k为偶数）
>A[k/2-1] == B[k/2-1] 说明A[k/2-1](B[k/2-1])即为我们要找的第k大的元素。因为
A[k/2-1]和B[k/2-1]都是比前面的k/2个元素大，比后面的元素小，因此这个数为第k大
>A[k/2-1] < B[k/2-1]：A[0...k/2-1]在第k个元素之外，直接可以删除。
>A[k/2-1] > B[k/2-1]：同理B[0...k/2-1]可以删除

现在我们来递归实现：
递归退出的条件为：
1.当A或B为空时，返回B[k-1]或者A[k-1]
2.k=1,返回min(A[0], B[0]);
3.A[k/2-1] == B[k/2-1],返回A[k/2-1]或B[k/2-1]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int sum = nums1.size() + nums2.size();
		if (sum & 0X1)		//为奇数时，中位数为中间的数
		{
			return findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum/2+1);
		}
		else
			return (findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum / 2) +
			findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum / 2 + 1))/2.0;
	}
	/*
	*参数说明：
	*A为数组A开始的迭代器，m为其长度，这样就确定了一个数组
	*B也同理
	*k为要查找的数的位子
	*/
	double findKth(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k)
	{
		//一直假设m<m
		if (m > n)
			return findKth(B, n, A, m, k);
		//递归终止条件
		if (m == 0)
			return *(B + k - 1);
		if (k == 1)
			return min(*A, *B);

		//将k分成两部分，不能超过A中元素个数m
		int ia = min(k / 2, m), ib = k - ia;
		//比较的三种情况
		if (*(A + ia - 1) < *(B + ib - 1))
			return findKth(A + ia, m - ia, B, n, k - ia);	//舍弃A中的元素
		else if (*(A + ia - 1) > *(B + ib - 1))
			return findKth(A, m, B + ib, n - ib, k - ib);	//舍弃B中的元素
		else
			return A[ia - 1];
	}
};


void TEST_findMedianSortedArrays()
{
	Solution sol;
	vector<int> v1{ 1,3 };
	vector<int> v2{ 2 };
	cout << sol.findMedianSortedArrays(v1, v2) << endl;
}

int main()
{
	TEST_findMedianSortedArrays();

	return 0;
}

