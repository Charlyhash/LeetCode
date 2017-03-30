/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

题目大意：从给定的链表中删除值为val的节点
解题思路：扫描一遍链表，如果值为val则删除
*/

#include <iostream>
#include "LeetCodeList.h"
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
	ListNode* removeElements(ListNode* head, int val) 
	{
		if (head == nullptr)
			return head;
		//ListNode* p = head;
		ListNode* tmp;
		while (head != nullptr && head->val == val)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		ListNode* p = head;
		if (head == nullptr)
			return head;
		while (p->next != nullptr)
		{
			if (p->next->val == val)
			{
				tmp = p->next;
				p->next = p->next->next;
				delete tmp;
			}
			else
				p = p->next;
		}

		return head;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1 });
	head = sol.removeElements(head, 1);
	PrintList(head);
}

int main()
{
	test();

	return 0;
}