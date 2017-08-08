/*
leetocde 155. Min Stack
题目大意：
设计一个栈，使其支持在O(1)时间push,pop,retrieving minimun element
解题思路：
使用两个栈来存放数据，第一个栈dataStk存放原始数据，第二个栈minStk存放最小值。
(1)对于push操作:push到dataStk,如果比minStk.top()小，则push到minStk,否则push
minStk.top()
(2)对于pop()操作：直接pop出两个栈的元素即可
(3)对于getMin()操作，直接返回minStk.top()即可
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		dataStk.push(x);
		if (minStk.empty())
			minStk.push(x);
		else
		{
			if (minStk.top() > x)
				minStk.push(x);
			else
				minStk.push(minStk.top());
		}
	}

	void pop() {
		if (!dataStk.empty())
		{
			dataStk.pop();
			minStk.pop();
		}
	}

	int top() {
		if (!dataStk.empty())
			return dataStk.top();
		return -1;
	}

	int getMin() {
		if (!minStk.empty())
			return minStk.top();
		return -1;
	}

private:
	stack<int> dataStk;
	stack<int> minStk;
};

int main()
{
	MinStack obj;
	vector<int> v{ 9,4,3,6,7,5,1,2 };
	for (auto num : v)
		obj.push(num);
	cout << obj.top() << endl;
	cout << obj.getMin() << endl;
	obj.pop();
	obj.pop();
	obj.pop();
	cout << obj.top() << endl;
	cout << obj.getMin() << endl;

	return 0;
}