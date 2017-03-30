/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

题目大意：从排序的链表中删除重复的元素
解题思路：用一个指针扫描链表，如果它的next节点元素值和它的元素值相等，就删除它的next节点，直到最后一个元素

*/

#include <iostream>
#include <vector>
#include <algorithm>
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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == nullptr)
			return head;
		ListNode* p = head;
		ListNode* tmp;
		while (p != nullptr)
		{
			tmp = p->next;
			while (tmp != nullptr && p->val == tmp->val)
			{
				p->next = p->next->next;
				delete tmp;
				tmp = p->next;
			}
			p = tmp;
		}

		return head;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,1});
	PrintList(head);
	sol.deleteDuplicates(head);
	PrintList(head);
}

int main()
{
	test();

	return 0;
}
