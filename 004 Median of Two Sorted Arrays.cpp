/*
leetcode 4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
�ο���https://github.com/soulmachine/leetcode
������������������ҵ���λ��
ʱ�临�Ӷ�Ҫ��ΪO(log(m+n))
����˼·��
���k���Ԫ�صķ���
1��ֱ�Ӻϲ��������飬Ȼ�����k�������ʱ�临�Ӷ�ΪO(m+n)
2��������ָ�룬pa��pb,�ֱ�ָ��A��B��������ĵ�һ��Ԫ�ء����A��Ԫ��С��pa++, m++;
���B��Ԫ��С��pb++,m++����m==kʱ�����Ǿ��ҵ������Ԫ��.ʱ�临�Ӷ�ΪO(k)
3����k���֣������һ��ɾ��һ����k֮ǰ��Ԫ�أ����Ӷ�Ӧ���ܴﵽҪ��
�ȼ���A��B�е�Ԫ�ض�����k/2,��A[k/2-1]��B[k/2-1]�Ƚϣ�kΪż����
>A[k/2-1] == B[k/2-1] ˵��A[k/2-1](B[k/2-1])��Ϊ����Ҫ�ҵĵ�k���Ԫ�ء���Ϊ
A[k/2-1]��B[k/2-1]���Ǳ�ǰ���k/2��Ԫ�ش󣬱Ⱥ����Ԫ��С����������Ϊ��k��
>A[k/2-1] < B[k/2-1]��A[0...k/2-1]�ڵ�k��Ԫ��֮�⣬ֱ�ӿ���ɾ����
>A[k/2-1] > B[k/2-1]��ͬ��B[0...k/2-1]����ɾ��

�����������ݹ�ʵ�֣�
�ݹ��˳�������Ϊ��
1.��A��BΪ��ʱ������B[k-1]����A[k-1]
2.k=1,����min(A[0], B[0]);
3.A[k/2-1] == B[k/2-1],����A[k/2-1]��B[k/2-1]

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
		if (sum & 0X1)		//Ϊ����ʱ����λ��Ϊ�м����
		{
			return findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum/2+1);
		}
		else
			return (findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum / 2) +
			findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), sum / 2 + 1))/2.0;
	}
	/*
	*����˵����
	*AΪ����A��ʼ�ĵ�������mΪ�䳤�ȣ�������ȷ����һ������
	*BҲͬ��
	*kΪҪ���ҵ�����λ��
	*/
	double findKth(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k)
	{
		//һֱ����m<m
		if (m > n)
			return findKth(B, n, A, m, k);
		//�ݹ���ֹ����
		if (m == 0)
			return *(B + k - 1);
		if (k == 1)
			return min(*A, *B);

		//��k�ֳ������֣����ܳ���A��Ԫ�ظ���m
		int ia = min(k / 2, m), ib = k - ia;
		//�Ƚϵ��������
		if (*(A + ia - 1) < *(B + ib - 1))
			return findKth(A + ia, m - ia, B, n, k - ia);	//����A�е�Ԫ��
		else if (*(A + ia - 1) > *(B + ib - 1))
			return findKth(A, m, B + ib, n - ib, k - ib);	//����B�е�Ԫ��
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

