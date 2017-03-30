/*
leetcode 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
Subscribe to see which companies asked this question
题目大意：判断一个单链表是不是回文的
解题思路：
找到中间的节点：快慢指针法。用两个指针，第一个指针每次前进一步，第二个指针每次前进两步
当第二个指针到链表尾的时候，第一个指针指向中间的节点(处理好边界问题)
反转链表
*/

#include <iostream>
#include <vector>
#include "LeetCodeList.h"
using namespace std;

class Solution {
public:
	bool isPalindrome(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return true;

		ListNode* mid = GetMiddle(head);
		

		ListNode* last = ReverseList(mid);
		while (last != nullptr && head != nullptr)
		{
			if (last->val != head->val)
			{
				return false;
			}
			last = last->next;
			head = head->next;
		}

		return true;
	}

	//reverse list
	//逆序一个链表
	ListNode* ReverseList(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* cur = head->next;
		ListNode* pre = head;
		pre->next = nullptr;
		ListNode* next = nullptr;
		while (cur != nullptr)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		return pre;
	}

	//获取中间的节点
	//奇数个节点为中间的节点，偶数个节点为n/2位置的节点
	ListNode* GetMiddle(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* lower = head;
		ListNode* faster = head;
		while (faster->next != nullptr && faster->next->next != nullptr)
		{
			lower = lower->next;
			faster = faster->next->next;
		}
		if (faster->next != nullptr)
			lower = lower->next;

		//cout << lower->val << endl;
		return lower;
	}
};

void test()
{
	vector<int> v{ 1,2,3,4,3,2,1 };
	ListNode* head= CreateList(v);
	Solution sol;
	cout << sol.isPalindrome(head) << endl;
}

void test2()
{
	ListNode* head;
	vector<int> v{ 1,2,3,4,5,6 };
	head = CreateList(v);

	PrintList(head);
	ListNode* mid = GetMiddle(head);

	ListNode* r = ReverseList(head);
	PrintList(r);
	
}

int main()
{
	test2();

	test();

	return 0;
}