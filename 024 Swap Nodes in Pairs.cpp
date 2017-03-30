/*
leetcode 24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

解题思路：申请一个节点指向头结点，然后从头结点开始交换。

*/

#include "LeetCodeList.h"
#include <iostream>
#include <string>
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
	ListNode* swapPairs(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		ListNode* nodeA = nullptr;
		ListNode* nodeB = nullptr;

 		while (cur != nullptr && cur->next != nullptr)
		{
			//交换cur和cur->next;
			nodeA = cur;
			nodeB = cur->next;
			nodeA->next = nodeB->next;
			nodeB->next = nodeA;
			pre->next = nodeB;

			pre = nodeA;
			cur = nodeA->next;
		}
		ListNode* ret = dummy->next;
		delete dummy;
		return ret;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4,5,6,7 });
	ListNode* rev = sol.swapPairs(head);
	PrintList(rev);
}

int main()
{
	test();

	return 0;
}