/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>
#include <vector>
#include <string>
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
	ListNode* reverseList(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pre = head;
		ListNode* cur = head->next;
		ListNode* tmp;
		pre->next = nullptr;
		while (cur != nullptr)
		{
			tmp = cur->next;
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
	ListNode* head = CreateList({ 1,2,3,4,5 });
	ListNode* reverseList = sol.reverseList(head);
	PrintList(reverseList);
}

int main()
{
	test();

	return 0;
}