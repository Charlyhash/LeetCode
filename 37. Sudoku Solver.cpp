/*
leetcode 37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

题目大意：解数独问题
解题思路：回溯，对于每一个没有填充的位置，依次填入0...9，看是不是满足数独的条件。
检查函数：check函数检查board是否满足数独的条件。先检查每一行和每一列处理自己外，有没有和其他位置的值相等的值
然后检查自己所在3*3的方格内有没有和自己相等的值。如果都没有，说明这次检查是正确的，即到目前位置，该数独是成立的。
解决函数：对于每一个位置，如果不为'.'，说明不需要填充这个方格，继续填下一个。如果为'.',则依次填入0...9,此时需要
该处的check成立并且solve下一个位置也成立。

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
		//判断行和列是不是有相等的值
		for (int i = 0; i < 9; ++i)
		{
			if (i != y && board[x][i] == board[x][y])
				return false;
			if (x != i && board[i][y] == board[x][y])
				return false;
		}

		//判断3*3格子里面是不是有相等的值
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