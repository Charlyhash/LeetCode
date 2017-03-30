/*
leetcode 23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		//¹é²¢
		int len = lists.size();
		if (len == 0)
			return nullptr;
		if (len == 1)
			return lists[0];
		vector<ListNode*> left;
		vector<ListNode*> right;
		int i = 0;
		for (; i < len / 2; ++i)
			left.push_back(lists[i]);
		for (; i < len; ++i)
			right.push_back(lists[i]);
		ListNode* l1 = mergeKLists(left);
		ListNode* l2 = mergeKLists(right);
		return mergeTwoLists(l1,l2);
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(1);
		ListNode* pre = dummy;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				pre->next = l1;
				l1 = l1->next;
				pre = pre->next;
			}
			else
			{
				pre->next = l2;
				l2 = l2->next;
				pre = pre->next;
			}
		}

		if (l1 == nullptr)
			pre->next = l2;
		if (l2 == nullptr)
			pre->next = l1;

		return dummy->next;
	}
};

void test()
{
	ListNode* l1 = CreateList({ 1,3,6,8 });
	ListNode* l2 = CreateList({ 0,5,9,14 });
	ListNode* l3 = CreateList({ 2,7,10 });
	ListNode* l4 = CreateList({ 4, 11, 12, 13 });
	vector<ListNode*> lists{ l1,l2,l3};
	Solution sol;
	ListNode* ret = sol.mergeKLists(lists);
	
	PrintList(ret);
}

int main()
{
	test();

	return 0;
}