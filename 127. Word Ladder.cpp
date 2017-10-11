/*
leetcode 127. Word Ladder
��Ŀ���⣺��ʼ���ַ���ΪbeginWord,�������ַ���ΪendWord���������ַ���������ͬ��
ͬʱ��һ��wordList�б������beginWord��ΪendWord�Ĳ������任����Ϊ��ÿ��ֻ��
�滻һ����ĸ���滻��ĵ��ʱ�����wordList�С�����޷��任���򷵻�0��

����˼·��BFS����beginWord�����ڶ����У��滻beginWord������ÿһ����ĸ�������
wordList�ж���û�б����ʹ����ͼ�����ӵ������С�ֱ����һ�η������ֵ����ҵ����ʵ�
ʱ���������ǡ����endWordΪֹ����ΪҪ����·�����ȣ������ڶ����д��string,int��
pair�ԣ���ʾ���ʺͱ任�Ĵ�����
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