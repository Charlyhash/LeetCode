#include "Header.h"

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		if (n < 1 || k == 0)
			return ret;
		
		vector<int> v;
		DFS(ret, n, k, 1, v);

		return ret;
	}

	void DFS(vector<vector<int>>& ret, int n, int k, int pos, vector<int> v)
	{
		if (k == 0)
		{
			ret.push_back(v);
			return;
		}
		else if (k > 0 && pos <= n)
		{
			v.push_back(pos);
			DFS(ret, n, k - 1, pos+1, v); //加入pos
			v.pop_back(); //继续递归
			DFS(ret, n, k, pos + 1, v); //不加入pos
		}
	}
};

void TEST_COM()
{
	Solution sol;
	vector<vector<int>> ret = sol.combine(4, 2);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	TEST_COM();
}
