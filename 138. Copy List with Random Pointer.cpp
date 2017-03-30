/*
leetcode 138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

解题思路：分两次遍历链表，第一次先复制普通的含有next的指针域，第二次复制random指针域
*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (!head)
			return head;
		unordered_map<RandomListNode*, RandomListNode*> map;
		RandomListNode* dummy = new RandomListNode(1);
		//dummy->next = head;
		RandomListNode* cur = head;			//原来的链表
		RandomListNode* pre = dummy;		//新链表空头结点
		RandomListNode* pre1 = dummy;

		//第一次遍历，复制next并打表：原始节点->新创建的节点
		while (cur)
		{
			pre->next = new RandomListNode(cur->label);
			map[cur] = pre->next;
			cur = cur->next;
			pre = pre->next;
		}
		//第二次遍历：复制random域，要想找到在新的链表中random域对应的节点，需要使用map中存储的对应关系。
		while (head)
		{
			pre1->next->random = map[head->random];//map保存的是旧节点和新节点的对应关系，可以根据旧节点找到新复制的节点。因此复制的链表的random域指向的节点可以通过map直接找到。
			head = head->next;
			pre1 = pre1->next;
		}

		return dummy->next;
	}
};