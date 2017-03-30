/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include "LeetCodeList.h"
#include<iostream>
#include <vector>

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
	void reorderList(ListNode* head) {
		if (head == nullptr)
			return;
		if (head->next == nullptr)
			return;
		if (head->next->next == nullptr)
			return;
		ListNode* mid = GetMiddle(head);
		
		ListNode* rev = ReverseList(mid->next);
		mid->next = nullptr;
		ListNode* p1 = head;
		ListNode* p2 = rev;
		while (p2 != nullptr)
		{
			ListNode* next1 = p1->next;
			ListNode* next2 = p2->next;
			p1->next = p2;
			p2->next = next1;
			p1 = next1;
			p2 = next2;
		}
	}

	//获取中间的节点
	//奇数个节点为中间的节点，偶数个节点为n/2位置的节点
	ListNode* GetMiddle(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* lower = head;
		ListNode* faster = head;
		while (faster->next != nullptr && faster->next->next != nullptr)
		{
			lower = lower->next;
			faster = faster->next->next;
		}
		//if (faster->next != nullptr)

		//cout << lower->val << endl;
		return lower;
	}

	//逆序一个链表
	ListNode* ReverseList(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* cur = head->next;
		ListNode* pre = head;
		pre->next = nullptr;
		ListNode* next = nullptr;
		while (cur != nullptr)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		return pre;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4,5,6 });
	sol.reorderList(head);
	PrintList(head);
}

int main()
{
	test();

	return 0;
}

