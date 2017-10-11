/*

*/

#include "Header.h"
#include "Listutl.h"
#include "Treeutl.h"

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		return GetMiddle(head, NULL);
	}

	TreeNode* GetMiddle(ListNode* head, ListNode* tail)
	{
		ListNode* fast = head; 
		ListNode* slow = head;
		if (head == tail)
			return NULL;
		while (fast != tail && fast->next != tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->left = GetMiddle(head, slow);
		root->right = GetMiddle(slow->next, tail);

		return root;
	}
};

int main()
{
	Solution sol;
	ListNode* head = CreateList({ 1,2,3,4,5,6 });
	TreeNode* root = sol.sortedListToBST(head);
	FirstOrderTraverse(root);

	return 0;
}