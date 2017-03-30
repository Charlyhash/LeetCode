/*
leetcode 147. Insertion Sort List

Sort a linked list using insertion sort.

解题思路：插入排序。
方法：扫描链表，如果当前节点cur的val比cur->next小，说明cur->next已经有序了
否则，cut的下一个节点应该为cur->next->next,并将cur->next应该插入到合适的位置。
插入cur->next的方法是找到一个节点tmp,tmp->next->val比它的值大，那么就要插在tmp后面。
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
		ListNode* dummy = new ListNode(-1);		//可以头插
		dummy->next = head;
		ListNode* cur = head;
		//ListNode* node = head;
		while (cur->next != nullptr)
		{
			if (cur->val <= cur->next->val) //cur->next已经有序
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