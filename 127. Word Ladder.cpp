/*
leetcode 127. Word Ladder
题目大意：开始的字符串为beginWord,结束的字符串为endWord，这两个字符串长度相同，
同时有一个wordList列表，计算从beginWord变为endWord的步数，变换规则为：每次只能
替换一个字母，替换后的单词必须在wordList中。如果无法变换，则返回0。

解题思路：BFS。将beginWord保存在队列中，替换beginWord单词中每一个字母，如果在
wordList中而且没有被访问过，就继续添加到队列中。直到有一次发现在字典中找到单词的
时候，这个单词恰好是endWord为止。因为要返回路径长度，所以在队列中存放string,int的
pair对，表示单词和变换的次数。
*/

#include "Header.h"

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_set<string> visit;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while (!q.empty())
		{
			pair<string, int> tmp = q.front();
			q.pop();
			string word = tmp.first;
			for (int i = 0; i < word.length(); ++i)
			{
				string newword = word;
				for (int j = 0; j < 26; ++j)
				{
					newword[i] = 'a' + j;
					if (dict.find(newword) != dict.end() && visit.find(newword) == visit.end())
					{
						if (newword == endWord)
							return tmp.second + 1;
						visit.insert(newword);
						q.push(make_pair(newword, tmp.second + 1));
					}
				}
			}
		}

		return 0;
	}
};

void TEST()
{
	Solution sol;

	vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
	cout << sol.ladderLength("hit", "cog", wordList) << endl;
}

int main()
{
	TEST();
}