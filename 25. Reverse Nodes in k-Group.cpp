/*
25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

题目大意：对于给定的链表，以k长度为1组进行旋转，如果长度小于k，那么就不旋转。
解题思路：找到要选择的前一个节点pre，起点start,终点end,终点的下一个节点next,
然后旋转start到end的节点，继续直到达到nullptr。在旋转之前要判断start到end的长度
如果长度小于k，说明不需要旋转了，如果end->next为nullptr，说明已经旋转完成。
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
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		if (k == 1)
			return head;
		ListNode* dummy = new ListNode(1);
		dummy->next = head;

		int len = 0;
		while (head != nullptr)
		{
			len++;
			head = head->next;
		}

		if (k == len)
			return ReverseList(dummy->next);

		//k =  k%len;

		ListNode* pre = dummy;
		ListNode* start = dummy->next;
		ListNode* end = dummy->next;
		ListNode* next;
		bool done = false;
		while (!done)
		{
			//选择子链表的长度
			int subLen = 1;
			for (int i = 1; (i < k) && (end->next != nullptr); ++i)
			{
				subLen++;
				end = end->next;
			}
			//子链表的长度小于k,说明旋转完成
			if (subLen < k)
				break;
			//end->next为nullptr,说明这个最后一个子链表
			if (end->next == nullptr)
				done = true;

			next = end->next;
			end->next = nullptr;
			ListNode* new_end = start;
			ListNode* new_start = ReverseList(start);
			pre->next = new_start;
			new_end->next = next;
			pre = new_end;
			start = end = new_end->next;
		}

		return dummy->next;
	}
};

void test()
{
	ListNode* head = CreateList({ 0,3,8,4,1,9,3 });
	Solution sol;
	ListNode* ret = sol.reverseKGroup(head, 9);
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}