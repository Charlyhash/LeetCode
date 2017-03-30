/*
leetcode 36. Valid Sudoku
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

��Ŀ���⣺�ж��ǲ�������������������
����˼·��
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
					continue;
				if (!check(board, i, j))
					return false;
			}
		}
		return true;
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

