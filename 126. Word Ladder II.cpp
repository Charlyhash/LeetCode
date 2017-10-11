/*
leetocde 126. Word Ladder II
题目大意：对于给定的开始单词beginWord和结尾单词endWord，找到变换路径使得beginWord
可以转换为endWord.其中每次只能变换一个字母且该变换的单词必须在wordList中。

解题思路：BFS
求路径本身：需要使用一颗树存放当前的路径。这里用string到vector<string>的hash表。表示
string的父节点的数组。
状态描述：此处的状态为一个单词
状态扩展：将单词的每一个字母替换为其他的25个字母，如果在wordList中，则可以为一个扩展
判重问题：不能让单词扩展为本层相同的单词，这样会导致死循环。用哈希表记录已经访问过的单词
和本层的单词。
*/
#include "Header.h"

class Solution {
public:
	vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_set<string> current, next; //当前层，下一层
		unordered_set<string> visited;
		unordered_map<string, vector<string>>  father; //树

		bool found = false;

		auto state_is_target = [&](const string& s) { return s == endWord; };
		auto state_extend = [&](const string& s) {
			unordered_set<string> result;
			for (size_t i = 0; i < s.size(); ++i)
			{
				string new_word(s);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);
					if ((dict.count(new_word) > 0 || new_word == endWord) && !visited.count(new_word))
						result.insert(new_word);
					swap(c, new_word[i]);
				}
			}
			return result;
		};

		current.insert(beginWord);
		while (!current.empty() && !found)
		{
			for (const auto& word : current) //判重
				visited.insert(word);
			
			for (const auto& word : current)
			{
				const auto new_states = state_extend(word);
				for (const auto& state : new_states)
				{
					if (state_is_target(state)) found = true;
					next.insert(state);
					father[state].push_back(word);//记录路径
				}
			}
			current.clear();
			swap(current, next);
		}

		vector<vector<string>> result;
		if (found)
		{
			vector<string> path;
			gen_path(father, path, beginWord, endWord, result);
		}
		return result;

	}

	void gen_path(unordered_map<string, vector<string>> &father,
		vector<string> &path, const string& beginWord,
		const string& word, vector<vector<string>> &result)
	{
		path.push_back(word);
		if (word == beginWord)
		{
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		}
		else
		{
			for (const auto& f : father[word])
				gen_path(father, path, beginWord, f, result);
		}
		path.pop_back();
	}
};

void TEST_sol()
{
	Solution sol;
	vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
	auto ret = sol.ladderLength("hit", "cog", wordList);
	for (const auto& v : ret)
	{
		for (const auto& str : v)
			cout << str << " ";
		cout << endl;
	}
}

int main()
{
	TEST_sol();
}