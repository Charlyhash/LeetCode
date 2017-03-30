/*
leetcode 208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node {
	//int count;
	bool isExit;
	vector<TrieNode*> next;
	TrieNode()
	{
		//count = 0;
		isExit = false;
		next = vector<TrieNode*>(26, NULL);
	}
}TrieNode;

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root =new TrieNode();
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

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/

void TEST()
{
	Trie* obj = new Trie();
	obj->insert("abc");
	cout << obj->search("abc") << endl;
	cout << obj->search("ab") << endl;
	obj->insert("ab");
	cout << obj->search("ab") << endl;
	obj->insert("ab");
	cout << obj->search("ab") << endl;
}

int main()
{
	TEST();

	return 0;
}