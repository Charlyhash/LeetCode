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

��Ŀ���⣺���ڸ�����������k����Ϊ1�������ת���������С��k����ô�Ͳ���ת��
����˼·���ҵ�Ҫѡ���ǰһ���ڵ�pre�����start,�յ�end,�յ����һ���ڵ�next,
Ȼ����תstart��end�Ľڵ㣬����ֱ���ﵽnullptr������ת֮ǰҪ�ж�start��end�ĳ���
�������С��k��˵������Ҫ��ת�ˣ����end->nextΪnullptr��˵���Ѿ���ת��ɡ�
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
			//ѡ��������ĳ���
			int subLen = 1;
			for (int i = 1; (i < k) && (end->next != nullptr); ++i)
			{
				subLen++;
				end = end->next;
			}
			//������ĳ���С��k,˵����ת���
			if (subLen < k)
				break;
			//end->nextΪnullptr,˵��������һ��������
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