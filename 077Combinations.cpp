/*
LeetCode 077Combinations �ݹ�/����
��Ŀ���⣺��������n��k,�ҳ�1-n��n�����ĸ���Ϊk��������
����˼·���ݹ�/����
�ο���http://blog.csdn.net/charles1e/article/details/51646879
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) 
	{
		vector<vector<int> > result;
		vector<int> path;
		DFS(n, k, 1, 0, path, result);
		return result;
	}

private:
	//����Ϊn,Ҫ�ҵ�����Ϊk�������У���ʼλ��Ϊstart,��ǰ����Ϊcur
	//path��¼����һ�������У�result��¼�����������
	void DFS(int n, int k, int start, int cur, vector<int>& path, vector<vector<int> > &result)
	{
		if (cur == k)
		{//�ݹ���ڣ�path���Ѿ�����k����
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			path.push_back(i);
			DFS(n, k, i + 1, cur + 1, path, result);	//�ݹ飺�����һ��Ԫ��
			path.pop_back();							//���ݣ�������ǰԪ�غ��������
		}
	}
};

int main()
{
	Solution sol;
	int n, m;
	cin >> n >> m;

	vector<vector<int> > result;
	result = sol.combine(n, m);

	for (auto v : result)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
/*
���룺
4 2
�����
4 2
1 2
1 3
1 4
2 3
2 4
3 4
*/