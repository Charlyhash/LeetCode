/*
leetcode 328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

����˼·����¼���ʹ��Ľڵ����һ������λ�õĽڵ㣬Ȼ�������λ�õĽڵ�鵽���һ������
�ڵ�ĺ��档
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
	ListNode* oddEvenList(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* lastOdd = head;		//last odd node
		ListNode* p = head->next;
		while (p->next != nullptr)
		{
			ListNode* cur = p->next;
			ListNode* nxt = lastOdd->next;
			p->next = p->next->next;
			lastOdd->next = cur;
			lastOdd = lastOdd->next;
			cur->next = nxt;
			p = p->next;
			if (p == nullptr)
				break;
		}

		return head;
		//return dummy->next;
	}
};


void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4,5,6 });
	ListNode* ret = sol.oddEvenList(head);

	PrintList(ret);
}

int main()
{
	test();

	return 0;
}

