/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Subscribe to see which companies asked this question

解题思路：
比较两个链表的元素，小的元素就加到新的链表中，直到其中一个链表到末尾，把另一个链表加到新链表中
*/

#include <iostream>
#include <vector>
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* head;
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		if (l1->val <= l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}
		
		ListNode* tmp = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				tmp->next = l1;
				l1 = l1->next;
				tmp = tmp->next;
			}
			else
			{
				tmp->next = l2;
				l2 = l2->next;
				tmp = tmp->next;
			}
		}

		if (l1 == nullptr)
		{
			while (l2 != nullptr)
			{
				tmp->next = l2;
				tmp = tmp->next;
				l2 = l2->next;
			}
		}
		else if (l2 == nullptr)
		{
			while (l1 != nullptr)
			{
				tmp->next = l1;
				tmp = tmp->next;
				l1 = l1->next;
			}
		}

		return head;
	}
};

void test()
{
	vector<int> v1{1,2,3,6,7,8};
	vector<int> v2{3,4,5,6};
	ListNode* l1 = CreateList(v1);
	ListNode* l2 = CreateList(v2);
	PrintList(l1);
	PrintList(l2);

	Solution sol;
	
	ListNode* ret = sol.mergeTwoLists(l1, l2);

	PrintList(ret);
}

int main()
{
	test();

	return 0;
}
