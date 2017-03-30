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
	bool hasCycle(ListNode *head) {

		if (head == nullptr)
			return false;
		ListNode* slower = head;
		ListNode* faster = head;

		while (true)
		{
			if (slower->next != nullptr)
				slower = slower->next;
			else
				return false;
			if (faster->next != nullptr && faster->next->next != nullptr)
				faster = faster->next->next;
			else
				return false;

			if (slower == faster)
				return true;
		}

		return false;
	}
};