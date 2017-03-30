/*
leetcode 2. Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

解题思路：新创建一个链表，然后扫描链表l1,l2，把他们的值以及进位，
个位为新链表下一个节点的值，十位为进位。
最后需要判断有没有进位，如果有就要创建一个值为1的节点。
*/

#include <iostream>
#include <vector>
#include <string>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* ret = new ListNode(0);
		ListNode* p = ret;
		int carry = 0;
		int sum = 0;
		while (l1 != nullptr || l2 != nullptr)
		{
			int val1 = (l1 == nullptr ? 0 : l1->val);
			int val2 = (l2 == nullptr ? 0 : l2->val);
			sum = val1 + val2 + carry;
			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
			}
			else
			{
				carry = 0;
			}
			p->next = new ListNode(sum);
			p = p->next;

			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;
		}

		if (carry)
			p->next = new ListNode(carry);

		ListNode* tmp = ret;
		ret = ret->next;

		delete tmp;

		return ret;	
	}
};

void test()
{
	Solution sol;
	ListNode* l1 = CreateList({ 2,4,3,1 });
	ListNode* l2 = CreateList({ 5,6,4 });
	ListNode* ret = sol.addTwoNumbers(l1, l2);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}