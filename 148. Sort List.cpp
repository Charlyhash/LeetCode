/*
leetcode 148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.

����˼·:��������м�ֳ���������Ȼ���ÿһ����������
*/


#include "LeetCodeList.h"
#include <iostream>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* sortList(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* slower = head;
		ListNode* faster = head;
		//�ֳ���������
		while (faster->next != nullptr && faster->next->next != nullptr)
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		ListNode* mid = slower->next;
		slower->next = nullptr;
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(mid);
		return mergeTwoLists(l1,l2);
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		//�ϲ�������������
		ListNode* dummy = new ListNode(1);
		ListNode* head1 = l1;
		ListNode* head2 = l2;
		ListNode* tail = dummy;
		while (head1 != nullptr && head2 != nullptr)
		{
			if (head1->val < head2->val)
			{
				tail->next = head1;
				head1 = head1->next;
			}
			else
			{
				tail->next = head2;
				head2 = head2->next;
			}

			tail = tail->next;
		}
		if (head1 == nullptr)
			tail->next = head2;
		if (head2 == nullptr)
			tail->next = head1;
		return dummy->next;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,9,3,2,4,5 });
	ListNode* ret = sol.sortList(head);
	PrintList(ret); 
}

int main()
{
	test();

	return 0;
}