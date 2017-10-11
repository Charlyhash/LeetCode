/*
leetcode 19.Remove Nth Node From End of List
题目大意：
删除链表中倒数第n个节点。
解题思路：
找到要删除的节点：用两个指针p1, p2，p1先走n步,然后两个同时走，
如果此时p1为null, 则删除的时头结点，当p1到链表尾部时，p2刚好
到要删除的节点的前一个位置
*/

#include "LeetCodeList.h"
#include <iostream>
#include <vector>
#include "LeetCodeList.h"

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{

		ListNode* p1 = head;
		ListNode* p2 = head;
		ListNode* t = NULL;
		for (int i = 0; i < n-1; ++i)
			p1 = p1->next;

		while (p1->next != nullptr)
		{
			t = p2;
			p1 = p1->next;
			p2 = p2->next;
		}

		if (t == NULL)
		{
			head = p2->next;
			delete p2;
		}
		else
		{
			t->next = p2->next;
			delete p2;
		}

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