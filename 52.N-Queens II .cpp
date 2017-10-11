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

		vector<int> C(n, 0); //C[i]��ʾ��i�лʺ����ڵ���
		dfs(C, 0);

		return count;
	}

private:
	int count; //����
	vector<int> columns; //��ռ�ݵ���
	vector<int> main_diag; //��ռ�ݵ����Խ���
	vector<int> anti_diag; //��ռ�ݵĸ��Խ���

	void dfs(vector<int>& C, int row)
	{
		const int N = C.size();
		if (row == N)
		{
			++count;
			return;
		}
		//���Խ��߷�����row+j���˵������ͬһ�����Խ����ϣ�����0,1��1,0
		//���Խ��߷�����row-j+N��ͬ˵����ͬһ�����Խ����ϣ����2,2��3,3
		for (int j = 0; j < N; ++j) //���ڵ�row�У�ÿһ�ж���һ��
		{
			//��֦
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