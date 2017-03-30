/*
leetcode 138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

����˼·�������α���������һ���ȸ�����ͨ�ĺ���next��ָ���򣬵ڶ��θ���randomָ����
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