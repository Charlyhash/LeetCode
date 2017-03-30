/*
leetcode 37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

��Ŀ���⣺����������
����˼·�����ݣ�����ÿһ��û������λ�ã���������0...9�����ǲ�������������������
��麯����check�������board�Ƿ������������������ȼ��ÿһ�к�ÿһ�д����Լ��⣬��û�к�����λ�õ�ֵ��ȵ�ֵ
Ȼ�����Լ�����3*3�ķ�������û�к��Լ���ȵ�ֵ�������û�У�˵����μ������ȷ�ģ�����Ŀǰλ�ã��������ǳ����ġ�
�������������ÿһ��λ�ã������Ϊ'.'��˵������Ҫ���������񣬼�������һ�������Ϊ'.',����������0...9,��ʱ��Ҫ
�ô���check��������solve��һ��λ��Ҳ������

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) 
	{
		solve(board, 0);
	}

	bool solve(vector<vector<char>>& board, int position)
	{
		if (position == 81)
			return true;

		int row = position / 9;
		int col = position % 9;

		if (board[row][col] != '.')
			return solve(board, position + 1);

		for (int i = 1; i <= 9; ++i)
		{
			board[row][col] = i + '0';
			if (check(board, row, col) && solve(board, position + 1))
				return true;
			board[row][col] = '.';
		}
		
		return false;		
	}

	bool check(vector<vector<char>>& board, int x, int y)
	{
		//�ж��к����ǲ�������ȵ�ֵ
		for (int i = 0; i < 9; ++i)
		{
			if (i != y && board[x][i] == board[x][y])
				return false;
			if (x != i && board[i][y] == board[x][y])
				return false;
		}

		//�ж�3*3���������ǲ�������ȵ�ֵ
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[x / 3 * 3 + i][y / 3 * 3 + j] == board[x][y] &&
					(x != x / 3 * 3 + i) && (y != y / 3 * 3 + j))
					return false;
			}
		}

		return true;
	}
};


void test()
{
	Solution sol;
	vector<vector<char>> board{
		{'.','.','9','7','4','8','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'.','2','.','1','.','9','.','.','.'},
		{'.','.','7','.','.','.','2','4','.'},
		{'.','6','4','.','1','.','5','9','.'},
		{'.','9','8','.','.','.','3','.','.'},
		{'.','.','.','8','.','3','.','2','.'},
		{'.','.','.','.','.','.','.','.','6'},
		{'.','.','.','2','7','5','9','.','.'}
	};

	sol.solveSudoku(board);

	for (auto v : board)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	test();

	return 0;
}