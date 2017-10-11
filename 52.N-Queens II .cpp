#include "Header.h"

class Solution
{
public:
	int totalNQueues(int n)
	{
		count = 0;
		columns = vector<int>(n, 0);
		main_diag = vector<int>(2 * n, 0);
		anti_diag = vector<int>(2 * n, 0);

		vector<int> C(n, 0); //C[i]表示第i行皇后所在的列
		dfs(C, 0);

		return count;
	}

private:
	int count; //总数
	vector<int> columns; //已占据的列
	vector<int> main_diag; //已占据的主对角线
	vector<int> anti_diag; //已占据的副对角线

	void dfs(vector<int>& C, int row)
	{
		const int N = C.size();
		if (row == N)
		{
			++count;
			return;
		}
		//副对角线分析：row+j相等说明是在同一条副对角线上，比如0,1和1,0
		//主对角线分析：row-j+N相同说明在同一条主对角线上，如果2,2和3,3
		for (int j = 0; j < N; ++j) //对于第row行，每一列都试一下
		{
			//剪枝
			const bool ok = columns[j] == 0 &&
				main_diag[row + j] == 0 &&
				anti_diag[row - j + N] == 0;
			if (!ok) continue;

			C[row] = j;
			columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
			dfs(C, row + 1);
			columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
		}
	}
};

void TEST_SOL()
{
	Solution sol;
	cout << sol.totalNQueues(5) << endl;
}

int main()
{
	TEST_SOL();
}