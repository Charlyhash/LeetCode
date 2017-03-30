/*
leetcode 130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions 
surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

题目大意：将被'X'包围的'O'换为'X'
解题思路：一定要读懂题目的意思。这里被'X'包围的'O'的对立一面就是在边缘上的'O'以及
和边缘连通的'O'
(1) BFS
(2) 并查集

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution1 {

private:
	vector<int> root;		//并查集的根节点
	vector<int> isEdge;		//是否为边缘上的'O'或其连通的
	vector<int> rank;		//树的高度，为了加速
	//初始化并查集
	void MakeSet(int len)
	{
		root = vector<int>(len, 0);
		isEdge = vector<int>(len, 0);
		rank = vector<int>(len, 0);
		for (int i = 0; i < len; ++i)
		{
			root[i] = i;
		}
	}
	//查找根节点
	int Find(int p)
	{
		int r = p;
		while (root[r] != r)
			r = root[r];	//find the root
		int tmp;
		while (p != r)		//路径压缩
		{
			tmp = root[p];
			root[p] = r;
			p = tmp;
		}

		return r;
	}
	//合并：这里要注意，合并时边缘也需要改变
	void Union(int p, int q)
	{
		p = Find(p);
		q = Find(q);
		if (p == q)
			return;
		if (rank[p] >= rank[q])
		{
			root[q] = p;
			if (isEdge[q])
				isEdge[p] = 1;
			if (rank[p] == rank[q])
				++rank[p];
		}
		else//(rank[q] > rank[p])
		{
			root[p] = q;
			if (isEdge[p])
				isEdge[q] = 1;
		}
	}
public:

	void solve(vector<vector<char>>& board) {

		int rows = board.size();
		if (rows == 0)
			return;
		int cols = board[0].size();
		if (rows < 3 || cols < 3)
			return;

		int len = rows*cols;
		//初始化
		MakeSet(len);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && (board[i][j] == 'O'))
				{
					isEdge[i*cols + j] = 1;
				}
			}
		}
		//合并连通域
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				//cout << "(" << i << "," << j << ")" << endl;
				if (board[i][j] == 'O' && i < rows - 1 && board[i][j] == board[i + 1][j] )
					Union(i*cols + j, (i + 1)*cols + j);
				if (board[i][j] == 'O' && j < cols - 1 && board[i][j] == board[i][j + 1])
					Union(i*cols + j, i*cols + j + 1);
			}
		}
		//替换
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (board[i][j] == 'O' && !isEdge[Find(i*cols + j)])
					board[i][j] = 'X';
			}
		}

	}
};

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int rows = board.size(); 
		if (rows == 0)
			return;
		int cols = board[0].size();
		if (rows < 3 || cols < 3)
			return;
		for (int i = 0; i < rows; ++i)
		{
			bfs(board, i, 0);
			bfs(board, i, cols - 1);
		}
		for (int j = 0; j < cols; ++j)
		{
			bfs(board, 0, j);
			bfs(board, rows - 1, j);
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'Q')
					board[i][j] = 'O';
			}
		}
	}

	void bfs(vector<vector<char>>& board, int x, int y)
	{
		int rows = board.size(); int cols = board[0].size();
		if (x < 0 || x >= board.size() || y < 0 || y > board[0].size() || board[x][y] != 'O')
			return;
		board[x][y] = 'Q';		//没有被包围
		//找四周的位置
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty())
		{
			auto t = q.front();
			q.pop();
			int tmp_x = t.first; int tmp_y = t.second;
			if (tmp_x > 0 && board[tmp_x - 1][tmp_y] == 'O')
			{
				board[tmp_x - 1][tmp_y] = 'Q';
				q.push(make_pair(tmp_x - 1, tmp_y));
			}
			if (tmp_x < rows-1 && board[tmp_x+1][tmp_y] == 'O')
			{
				board[tmp_x + 1][tmp_y] = 'Q';
				q.push(make_pair(tmp_x + 1, tmp_y));
			}
			if (tmp_y > 0 && board[tmp_x][tmp_y - 1] == 'O')
			{
				board[tmp_x][tmp_y - 1] = 'Q';
				q.push(make_pair(tmp_x, tmp_y-1));
			}
			if (tmp_y < cols - 1 && board[tmp_x][tmp_y + 1] == 'O')
			{
				board[tmp_x][tmp_y+1] = 'Q';
				q.push(make_pair(tmp_x, tmp_y+1));
			}
		}

	}
};

void TEST()
{
	/*vector<vector<char>>v {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};*/
	vector<vector<char>>v{
		{ 'X', 'O', 'X', 'X' },
		{ 'O', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'O' },
		{ 'O', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'O' },
		{ 'O', 'X', 'O', 'X' }
	};
	Solution sol;

	sol.solve(v);

	for (auto vec : v)
	{
		for (auto ch : vec)
			cout << ch << " ";
		cout << endl;
	}
}

int main()
{
	TEST();

	return 0;
}