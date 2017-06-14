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

题目大意：

os中缺页的调度算法中，LRU（least recently used）最近最少使用算法
引用比较广泛，比如memcached的缓存命中是使用LRU的。LRU实现简单，有
较高的命中率。LRU使用双向链表+哈希表组成。
LRU算法的操作有如下两种：
1. put(key, value)：如果在map中，则设置对应的值，然后获取对于节点从链表删除并
移动到链表头部；如果不存在则新建一个节点并插入头部。如果缓存已满，则删除链表最
后一个节点；
2. get(key):访问一个页面。如果存在则访问并放到链表头部，并返回对于的value，如果
不存在则返回-1.

解题思路：
使用一个双向链表和一个unordered_map
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
	int size;		//容量
	list<Node> l;		//链表记录
	unordered_map<int, list<Node>::iterator> map;//记录key，iter


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