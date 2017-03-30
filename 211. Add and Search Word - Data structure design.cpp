/*
leetcode 211. Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

解题思路：字典树
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode;

struct TrieNode {
	bool isExit;
	vector<TrieNode*> next;

	TrieNode() :isExit(false)
	{
		next = vector<TrieNode*>(26, NULL);
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* p = root;

		for (auto ch : word)
		{
			if (!p->next[ch - 'a'])
				p->next[ch - 'a'] = new TrieNode();

			p = p->next[ch - 'a'];
		}
		p->isExit = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return searchHelp(word, root, 0);
	}

	bool searchHelp(string word, TrieNode* node, int pos)
	{
		if (pos == word.size())
			return node->isExit;
		if (word[pos] == '.')
		{
			for (int i = 0; i < 26; ++i)
			{
				if (node->next[i] && searchHelp(word, node->next[i], pos + 1))
					return true;
			}

			return false;
		}
		else
			return (node->next[word[pos] - 'a'] && searchHelp(word, node->next[word[pos] - 'a'], pos + 1));
	}

private:
	TrieNode* root;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/

void TEST()
{
	WordDictionary* wd = new WordDictionary();
	wd->addWord("bad");
	wd->addWord("dad");
	wd->addWord("mad");

	cout << wd->search("pad") << endl;
	cout << wd->search("bad") << endl;
	cout << wd->search(".ad") << endl;
	cout << wd->search("b..") << endl;
}

int main()
{
	TEST();

	return 0;
}