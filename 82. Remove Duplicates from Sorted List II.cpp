/*
82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

����˼·�����������ҵ����ظ��Ľڵ㣬Ȼ��ɾ��
*/

#include <iostream>
#include "LeetCodeList.h"
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
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if (head == nullptr)
			return nullptr;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		while (pre->next != nullptr)
		{
			//�ڵ�ֵΪtarget��Ҫɾ��
			int target = pre->next->val;
			ListNode* cur = pre->next->next;
			while (cur != nullptr && cur->val == target)
				cur = cur->next;
			//û���ظ�������ɾ
			if (cur == pre->next->next)
			{
				pre = pre->next;
			}
			else
			{
				//���ظ��ģ���pre->nextɾ��cur(������cur)
				ListNode* tmp = pre->next;
				ListNode* p = pre->next;
				while (p != cur)
				{
					tmp = p;
					p = p->next;
					delete tmp;
				}

				pre->next = cur;				
			}
		}

		return dummy->next;
	}
};

void test()
{
	Solution sol;
	ListNode* head = CreateList({ 1,1,2,2,3,4,5,5,6,7,7 });
	ListNode* ret = sol.deleteDuplicates(head);
	//sol.deleteDuplicates();
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}