/*
leetcode 92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 �� m �� n �� length of list.
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "LeetCodeList.h"

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
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (head == nullptr || head->next == nullptr || m == n)
			return head;
		int pos = 1;
		ListNode* p = head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;		//λ��Ϊm��ǰһ���ڵ�
		while (pre->next != nullptr && pos < m)
		{
			pre = pre->next;
			++pos;
		}
		//m���ܳ��Ȼ�Ҫ��
		if (pos < m)
			return head;

		ListNode* mNode = pre->next;//mλ�õĽڵ�
		ListNode* curNode = mNode->next;//��ǰ����Ľڵ�
		//ÿ�ΰѵ�ǰ�Ľڵ�ŵ�pre�ڵ�ĺ���
		while (curNode != nullptr && pos < n)
		{
			ListNode* tmp = curNode->next;
			curNode->next = pre->next;
			pre->next = curNode;
			mNode->next = tmp;
			curNode = tmp;
			pos++;
		}

		return dummy->next;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4,5,6,7,8,9 });
	ListNode* res = sol.reverseBetween(head, 2, 6);
	PrintList(res);
}

int main()
{
	test();

	return 0;
}

