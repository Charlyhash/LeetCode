/*
leetcode 232. Implement Queue using Stacks
��Ŀ���⣺
ʹ��ջʵ�ֶ���
����˼·��
ʹ������ջs1,s2��
�����ʱ��ѹ�뵽s1�У�������ʱ�����s2Ϊ�գ���ô��s1�е�Ԫ�ص��������뵽s2�У���s2����
һ��Ԫ�أ����s2��Ϊ�գ���ôֱ�ӵ���s2����
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ret = peek();
		if (!s2.empty())
			s2.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		if (!s2.empty())
			return s2.top();
		return -1;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (s1.empty() && s2.empty())
			return true;
		return false;
	}

private:
	stack<int> s1;
	stack<int> s2;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/

int main()
{
	MyQueue obj;
	cout << obj.empty() << endl;
	obj.push(2); obj.push(1);
	cout << obj.peek() << endl;
	cout << obj.pop() << endl;
	obj.push(4); obj.push(3);
	cout << obj.peek() << endl;

	return 0;
}