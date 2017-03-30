/*
leetcode 86. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

解题思路：维护两个链表，一个链表中节点的值是比val小，一个链表中节点的值>=val.
扫描链表，然后根据节点值的大小不同，接到不同的链表中。最后将链表连起来。
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
	ListNode* partition(ListNode* head, int x) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* smallerDummy = new ListNode(1);
		ListNode* largerDummy = new ListNode(1);
		ListNode* smallerNode = smallerDummy;
		ListNode* largerNode = largerDummy;
		ListNode* node = head;
		while (node != nullptr)
		{
			if (node->val < x)
			{
				smallerNode->next = node;
				node = node->next;
				smallerNode = smallerNode->next;
			}
			else
			{
				largerNode->next = node;
				node = node->next;
				largerNode = largerNode->next;
			}
		}
		smallerNode->next = largerDummy->next;
		largerNode->next = nullptr;

		return smallerDummy->next;

	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,3,5,6,2,4 });
	ListNode* ret = sol.partition(head, 3);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}
