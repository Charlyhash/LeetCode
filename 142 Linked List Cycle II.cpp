/*

leetcode 142 Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

解题思路：用一个set存放访问过的指针，先检查是否已经在set中，如果有的说明已经访问过了，有环。
*/

#include "LeetCodeList.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

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
	ListNode *detectCycle(ListNode *head) 
	{
		if (head == nullptr)
			return nullptr;
		unordered_set<ListNode*> s;
		ListNode* p = head;
		while (p != nullptr)
		{
			if (s.find(p) != s.end())
				return p;
			s.insert(p);
			p = p->next;
		}

		return nullptr;
	}
};