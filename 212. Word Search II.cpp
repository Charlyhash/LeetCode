#include "Header.h"

class Solution {
private:
	struct TrieNode {
		bool exit;
		vector<TrieNode*> next;
		TrieNode() : exit(false)
		{
			next = vector<TrieNode*>(26, NULL);
		}
	};
	void insertTrie(string str)
	{
		TrieNode* p = root;
		for (auto ch : str)
		{
			if (p->next[ch - 'a'] == NULL)
			{
				TrieNode* tmp = new TrieNode();
				p->next[ch - 'a'] = tmp;
			}
			p = p->next[ch - 'a'];
		}
		p->exit = true;
	}
	bool findTrie(string str)
	{
		TrieNode* p = root;
		for (auto ch : str)
		{
			if (p->next[ch - 'a'] == NULL)
				return false;
		}
		return true;
	}
	TrieNode* root = new TrieNode;

	void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, string word, set<string>& result)
	{
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' ') return;
		//cout << "i=" << i << ",j=" << j << endl;
		if (p->next[board[i][j] - 'a'] != NULL)
		{
			word = word + board[i][j];
			p = p->next[board[i][j] - 'a'];
			if (p->exit)
				result.insert(word);
			char ch = board[i][j];
			board[i][j] = ' ';
			dfs(board, i + 1, j, p, word, result);
			dfs(board, i - 1, j, p, word, result);
			dfs(board, i, j + 1, p, word, result);
			dfs(board, i, j - 1, p, word, result);
			board[i][j] = ch;
		}
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		vector<string> ret;
		int m = board.size();
		if (m == 0)
			return ret;
		int n = board[0].size();
		set<string> s;
		for (auto str : words)
			insertTrie(str);

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dfs(board, i, j, root, "", s);
			}
		}
		for (auto str : s)
			ret.push_back(str);
		return ret;
	}
};

void TEST_FIND_WORDS()
{
	Solution sol;
	vector<vector<char>> board
	{
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};

	vector<string> words{"oath", "pea", "eat", "rain"};
	
	vector<string> ret = sol.findWords(board, words);
	for (auto s : ret)
		cout << s << " ";
	cout << endl;
}

int main()
{
	TEST_FIND_WORDS();
}