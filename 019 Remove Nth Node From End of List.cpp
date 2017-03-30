/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

����˼·��
�ҵ�Ҫɾ���Ľڵ�Ϳ����ˡ�
������ָ��p1, p2��p1����n��,Ȼ������ͬʱ�ߣ���p1������β��ʱ��p2�պõ�Ҫɾ����Ԫ�ص�λ�á�
*/


#include "LeetCodeList.h"
#include <iostream>
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
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		//if (n == 1)
		//{
		//	ListNode* tmp = head;
		//	head = head->next;
		//	delete tmp;
		//	return head;
		//}

		ListNode* p1 = head;
		ListNode* p2 = head;
		while (--n && p2->next != nullptr)
			p2 = p2->next;

		if (p2->next == nullptr)
		{
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
			return head;
		}

		while (p2->next->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		ListNode* tmp = p1->next;
		p1->next = p1->next->next;
		
		delete tmp;

		return head;
	}
};

void test()
{
	Solution sol;
	vector<int> v{1,2,3,4,5};
	ListNode* head = CreateList(v);
	ListNode* ret =  sol.removeNthFromEnd(head, 2);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}