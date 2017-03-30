/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
¨K
c1 ¡ú c2 ¡ú c3
¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include "LeetCodeList.h"
#include <iostream>
#include <string>
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		int len1 = 1;
		while (p1->next != nullptr)
		{
			++len1;
			p1 = p1->next;
		}
		int len2 = 1;
		while (p2->next != nullptr)
		{
			++len2;
			p2 = p2->next;
		}
		if (p1 != p2)
			return nullptr;

		if (len1 > len2)
		{
			int diff = len1 - len2;
			while (diff--)
				headA = headA->next;
		}
		if (len2 > len1)
		{
			int diff = len2 - len1;
			while (diff--)
				headB = headB->next;
		}

		while (headA != headB)
		{
				headA = headA->next;
				headB = headB->next;
		}

		return headA;
	}
};

void test()
{

}

int main()
{

}