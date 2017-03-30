/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

解题思路：先找到要旋转的节点，然后放到最前面。
*/

#include "LeetCodeList.h"
#include <iostream>
#include <vector>
#include <string>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution 
{
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		int len = 0;
		ListNode* p = head;
		while (p != nullptr)
		{
			len++;
			p = p->next;
		}
		//cout << len << endl;
		if (k == len)
			return head;

		int n = len - (k%len);
		p = head;
		int pos = 1;
		while (pos < n)
		{
			p = p->next;
			++pos;
		}
		//cur是开始旋转的节点
		ListNode* cur = p->next;
		if (cur == nullptr)
			return head;
		ListNode* newHead = cur;
		p->next = nullptr;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		
		cur->next = head;

		return newHead;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4 });
	ListNode* ret  = sol.rotateRight(head, 0);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}