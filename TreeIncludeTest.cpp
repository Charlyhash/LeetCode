#include "TreeInclude.h"

void TEST()
{
	vector<int> v{ 1,2,3,4,5 };
	TreeNode* root = CreateTree(v);
	FirstOrderTraverse(root);
	cout << endl;
	cout << "-----------------------" << endl;
	FirstOrderTraverseIter(root);
	cout << "-----------------------" << endl;
	InorderTraverse(root);
	cout << endl;
	cout << "-----------------------" << endl;
	InorderTraverseIter(root);
	cout << "-----------------------" << endl;
	PostorderTraverse(root);
	cout << endl;
	cout << "-----------------------" << endl;
	PostorderTraverseIter(root);
	cout << endl;
	cout << endl;
	MakeEmpty(root);
	printf("Make empty OK!\n");
}

int main()
{
	TEST();

	return 0;
}
