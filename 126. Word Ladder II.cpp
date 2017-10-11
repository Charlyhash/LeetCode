/*
leetocde 126. Word Ladder II
��Ŀ���⣺���ڸ����Ŀ�ʼ����beginWord�ͽ�β����endWord���ҵ��任·��ʹ��beginWord
����ת��ΪendWord.����ÿ��ֻ�ܱ任һ����ĸ�Ҹñ任�ĵ��ʱ�����wordList�С�

����˼·��BFS
��·��������Ҫʹ��һ������ŵ�ǰ��·����������string��vector<string>��hash����ʾ
string�ĸ��ڵ�����顣
״̬�������˴���״̬Ϊһ������
״̬��չ�������ʵ�ÿһ����ĸ�滻Ϊ������25����ĸ�������wordList�У������Ϊһ����չ
�������⣺�����õ�����չΪ������ͬ�ĵ��ʣ������ᵼ����ѭ�����ù�ϣ���¼�Ѿ����ʹ��ĵ���
�ͱ���ĵ��ʡ�
*/
#include "Header.h"

class Solution {
public:
	vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_set<string> current, next; //��ǰ�㣬��һ��
		unordered_set<string> visited;
		unordered_map<string, vector<string>>  father; //��

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
			for (const auto& word : current) //����
				visited.insert(word);
			
			for (const auto& word : current)
			{
				const auto new_states = state_extend(word);
				for (const auto& state : new_states)
				{
					if (state_is_target(state)) found = true;
					next.insert(state);
					father[state].push_back(word);//��¼·��
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