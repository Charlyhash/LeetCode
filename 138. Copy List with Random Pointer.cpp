/*
leetcode 138. Copy List with Random Pointer
��Ŀ���⣺���ڻ�����һ��ָ����Random��������и��ơ�

����˼·��
(1)ʹ�ù�ϣ�������α���������һ���ȸ�����ͨ�ĺ���next��ָ����
����¼�¾ɽڵ��map���ڶ��θ���randomָ����
(2)����������һ�ȸ��ƽڵ㣬�����뵽�ɽڵ�֮��Ȼ����random�����
������ֽ��������������������������
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
		RandomListNode* cur = head;			//ԭ��������
		RandomListNode* pre = dummy;		//�������ͷ���
		RandomListNode* pre1 = dummy;

		//��һ�α���������next�����ԭʼ�ڵ�->�´����Ľڵ�
		while (cur)
		{
			pre->next = new RandomListNode(cur->label);
			map[cur] = pre->next;
			cur = cur->next;
			pre = pre->next;
		}
		//�ڶ��α���������random��Ҫ���ҵ����µ�������random���Ӧ�Ľڵ㣬��Ҫʹ��map�д洢�Ķ�Ӧ��ϵ��
		while (head)
		{
			pre1->next->random = map[head->random];//map������Ǿɽڵ���½ڵ�Ķ�Ӧ��ϵ�����Ը��ݾɽڵ��ҵ��¸��ƵĽڵ㡣��˸��Ƶ������random��ָ��Ľڵ����ͨ��mapֱ���ҵ���
			head = head->next;
			pre1 = pre1->next;
		}

		return dummy->next;
	}
};