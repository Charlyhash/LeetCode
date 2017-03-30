/*
leetcode 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
Subscribe to see which companies asked this question
��Ŀ���⣺�ж�һ���������ǲ��ǻ��ĵ�
����˼·��
�ҵ��м�Ľڵ㣺����ָ�뷨��������ָ�룬��һ��ָ��ÿ��ǰ��һ�����ڶ���ָ��ÿ��ǰ������
���ڶ���ָ�뵽����β��ʱ�򣬵�һ��ָ��ָ���м�Ľڵ�(����ñ߽�����)
��ת����
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
	//����һ������
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

	//��ȡ�м�Ľڵ�
	//�������ڵ�Ϊ�м�Ľڵ㣬ż�����ڵ�Ϊn/2λ�õĽڵ�
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