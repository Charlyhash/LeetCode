/*
leetocde 155. Min Stack
��Ŀ���⣺
���һ��ջ��ʹ��֧����O(1)ʱ��push,pop,retrieving minimun element
����˼·��
ʹ������ջ��������ݣ���һ��ջdataStk���ԭʼ���ݣ��ڶ���ջminStk�����Сֵ��
(1)����push����:push��dataStk,�����minStk.top()С����push��minStk,����push
minStk.top()
(2)����pop()������ֱ��pop������ջ��Ԫ�ؼ���
(3)����getMin()������ֱ�ӷ���minStk.top()����
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