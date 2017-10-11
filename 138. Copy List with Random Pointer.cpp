/*
leetcode 138. Copy List with Random Pointer
题目大意：对于还有另一个指针域Random的链表进行复制。

解题思路：
(1)使用哈希表，分两次遍历链表，第一次先复制普通的含有next的指针域，
并记录新旧节点的map，第二次复制random指针域
(2)分三步，第一先复制节点，并插入到旧节点之后，然后复制random，最后
将链表分解成两个链表。返回新生产的链表。
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
	RandomListNode *copyRandomList2(RandomListNode *head)
	{
			if (head == NULL)
				return NULL;
			RandomListNode* p = head;
			RandomListNode* next = NULL;
			while (p != NULL)
			{
				next = p->next;
				RandomListNode* q = new RandomListNode(p->label);
				p->next = q;
				q->next = next;
				p = next;
			}

			p = head;
			while (p != NULL)
			{
				if (p->random != NULL)
					p->next->random = p->random->next;
				p = p->next->next;
			}

			p = head;
			RandomListNode* dummy = new RandomListNode(-1);
			RandomListNode* copy;
			RandomListNode* q = dummy;
			while (p != NULL)
			{
				next = p->next->next;
				copy = p->next;
				q->next = copy;
				q = copy;
				
				p->next = next;
				p = next;
			}

			return dummy->next;
		}
	};
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