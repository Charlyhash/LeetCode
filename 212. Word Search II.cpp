/*
leetcode 
Given a 2D board and a list of words from the dictionary, find all 
words in the board.Each word must be constructed from letters of 
sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may 
not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
	//int count;
	bool isExit;
	vector<TrieNode*> next;
	TrieNode()
	{
		//count = 0;
		isExit = false;
		next = vector<TrieNode*>(26, NULL);
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;

		for (auto ch : word)
		{
			if (p->next[ch - 'a'] == NULL)
			{
				p->next[ch - 'a'] = new TrieNode();
			}
			p = p->next[ch - 'a'];
		}
		p->isExit = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;

		for (auto ch : word)
		{
			if (p->next[ch - 'a'] == NULL)
				return false;
			p = p->next[ch - 'a'];
		}

		return p->isExit;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* p = root;
		if (p == NULL)
			return false;
		for (auto ch : prefix)
		{
			if (p->next[ch - 'a'] == NULL)
				return false;
			p = p->next[ch - 'a'];
		}
		return true;
	}

private:
	TrieNode* root;
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{

	}
};