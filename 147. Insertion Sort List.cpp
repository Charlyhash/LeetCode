/*
leetcode 147. Insertion Sort List

Sort a linked list using insertion sort.

����˼·����������
������ɨ�����������ǰ�ڵ�cur��val��cur->nextС��˵��cur->next�Ѿ�������
����cut����һ���ڵ�Ӧ��Ϊcur->next->next,����cur->nextӦ�ò��뵽���ʵ�λ�á�
����cur->next�ķ������ҵ�һ���ڵ�tmp,tmp->next->val������ֵ����ô��Ҫ����tmp���档
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
class Solution 
{
public:
	ListNode* insertionSortList(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* dummy = new ListNode(-1);		//����ͷ��
		dummy->next = head;
		ListNode* cur = head;
		//ListNode* node = head;
		while (cur->next != nullptr)
		{
			if (cur->val <= cur->next->val) //cur->next�Ѿ�����
				cur = cur->next;
			else
			{
				ListNode* node = cur->next;
				cur->next = cur->next->next;
				ListNode* tmp = dummy;
				while (tmp->next->val < node->val)
					tmp = tmp->next;
				ListNode* nextNode = tmp->next;
				tmp->next = node;
				node->next = nextNode;
			}

		}

		return dummy->next;
	}
};

void test()
{
	Solution sol;
	ListNode* l = CreateList({ 4,3,1,2,5 });
	ListNode* ret = sol.insertionSortList(l);
	PrintList(ret);
}

int main()
{
	test();
	return 0;
}