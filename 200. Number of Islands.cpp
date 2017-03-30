/*
leetcode 200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

解题思路：
(1) DFS
(2) 并查集
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if (grid.size() == 0)
			return 0;
		int rows = grid.size();
		int clos = grid[0].size();
		int res = 0;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < clos; ++j)
			{
				if (grid[i][j] == '1')
					++res;
				DFS(grid, i, j);	//标记周围方格
			}
		}

		return res;
	}


	void DFS(vector<vector<char>>& grid, int i, int j)
	{
		if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
			return;
		grid[i][j] = '0';
		DFS(grid, i + 1, j);
		DFS(grid, i - 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i, j - 1);
	}
};

class UnionFind {
public:
	UnionFind(int n)
	{
		count = n;
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	~UnionFind() {};

	void Union(int p, int q)
	{
		int i = root(p);
		int j = root(q);

		if (i == j)
		{
			return;
		}
		if (rank[i] < rank[j])
			parent[i] = j;
		else if (rank[i] > rank[j])
			parent[j] = i;
		else
		{
			parent[i] = j;
			++rank[j];
		}
		--count;
	} 

	bool Connect(int p, int q)
	{
		return root(p) == root(q);
	}

	int GetCount()
	{
		return count;
	}

private:
	vector<int> parent;	//父节点指针
	vector<int> rank;	//树的大小
	int count;			//树的数目

	int root(int i)
	{
		while (i != parent[i])
		{
			parent[i] = parent[parent[i]];
			i = parent[i];
		}

		return i;
	}
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		if (grid.size() == 0)
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		int dummy = rows*cols;
		UnionFind uf(rows*cols + 1);	//最后一个表示是所有0的集合
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (grid[i][j] == '1')
				{
					if (j != cols - 1 && grid[i][j + 1] == '1')
						uf.Union(i*cols + j, i*cols + j + 1);
					if (i != rows - 1 && grid[i + 1][j] == '1')
						uf.Union(i*cols + j, (i + 1)*cols + j);
				}
				else
					uf.Union(i*cols + j, dummy);
			}
		}


		return uf.GetCount() - 1;
	}
};


void TEST()
{
	vector<vector<char>> grid{ 
		{ '1','1','0','0','0'},
		{'1','1','0','0','0' },
		{'0','0','1','0','0'},
		{'0','0','0','1','1' }};

	Solution sol;
	int ret = sol.numIslands(grid);
	cout << ret << endl;
}

int main()
{
	TEST();

	return 0;
}