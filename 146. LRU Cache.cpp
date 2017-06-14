/*
leetcode 146

Design and implement a data structure for Least Recently Used (LRU) 
cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if 
the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already
present. When the cache reached its capacity, it should invalidate 
the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(capacity);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

��Ŀ���⣺

os��ȱҳ�ĵ����㷨�У�LRU��least recently used���������ʹ���㷨
���ñȽϹ㷺������memcached�Ļ���������ʹ��LRU�ġ�LRUʵ�ּ򵥣���
�ϸߵ������ʡ�LRUʹ��˫������+��ϣ����ɡ�
LRU�㷨�Ĳ������������֣�
1. put(key, value)�������map�У������ö�Ӧ��ֵ��Ȼ���ȡ���ڽڵ������ɾ����
�ƶ�������ͷ����������������½�һ���ڵ㲢����ͷ�������������������ɾ��������
��һ���ڵ㣻
2. get(key):����һ��ҳ�档�����������ʲ��ŵ�����ͷ���������ض��ڵ�value�����
�������򷵻�-1.

����˼·��
ʹ��һ��˫�������һ��unordered_map
*/

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (map.find(key) != map.end())
		{
			auto iter = map[key];
			l.splice(l.begin(), l, iter);
			map[key] = l.begin();
			return l.begin()->value;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		if (map.find(key) == map.end())
		{
			if (l.size() == size)
			{
				map.erase(l.back().key);
				l.pop_back();
			}
			Node node(key, value);
			l.insert(l.begin(), node);
			map[key] = l.begin();
		}
		else
		{
			auto iter = map[key];
			l.splice(l.begin(), l, iter);
			map[key] = l.begin();
			l.begin()->value = value;
		}
	}

private:
	struct Node {
		int key;
		int value;
		Node(int k, int v) :key(k), value(v) {}
	};
	int size;		//����
	list<Node> l;		//�����¼
	unordered_map<int, list<Node>::iterator> map;//��¼key��iter


	LRUCache() = delete;
	LRUCache(const LRUCache&) = delete;
	LRUCache& operator=(const LRUCache&) = delete;
};

int main()
{
	LRUCache* lru = new LRUCache(2);
	int ret;
	lru->put(1, 1);
	lru->put(2, 2);
	ret = lru->get(1);
	cout << ret << endl;
	lru->put(3, 3);
	ret = lru->get(2);
	cout << ret << endl;
	lru->put(4, 4);
	ret = lru->get(1);
	cout << ret << endl;
	ret = lru->get(3);
	cout << ret << endl;
	ret = lru->get(4);
	cout << ret << endl;

	return 0;
}