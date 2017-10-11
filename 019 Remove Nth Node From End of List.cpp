/*
leetcode 19.Remove Nth Node From End of List
��Ŀ���⣺
ɾ�������е�����n���ڵ㡣
����˼·��
�ҵ�Ҫɾ���Ľڵ㣺������ָ��p1, p2��p1����n��,Ȼ������ͬʱ�ߣ�
�����ʱp1Ϊnull, ��ɾ����ʱͷ��㣬��p1������β��ʱ��p2�պ�
��Ҫɾ���Ľڵ��ǰһ��λ��
*/

#include "LeetCodeList.h"
#include <iostream>
#include <vector>
#include "LeetCodeList.h"

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{

		ListNode* p1 = head;
		ListNode* p2 = head;
		ListNode* t = NULL;
		for (int i = 0; i < n-1; ++i)
			p1 = p1->next;

		while (p1->next != nullptr)
		{
			t = p2;
			p1 = p1->next;
			p2 = p2->next;
		}

		if (t == NULL)
		{
			head = p2->next;
			delete p2;
		}
		else
		{
			t->next = p2->next;
			delete p2;
		}

		return head;
	}
};

void test()
{
	Solution sol;
	vector<int> v{1,2,3,4,5};
	ListNode* head = CreateList(v);
	ListNode* ret =  sol.removeNthFromEnd(head, 2);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}