/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.

解题思路：把下一个节点的值复制过来，删除下一个节点。
*/

#include <iostream>

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
	void deleteNode(ListNode* node) 
	{
		ListNode* tmp = node->next;
		node->val = node->next->val;
		node->next = node->next->next;
		delete tmp;
	}
};

void test()
{

}

int main()
{
	test();

	return 0;
}