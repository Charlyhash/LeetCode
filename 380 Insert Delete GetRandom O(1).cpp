/*
leetcode 380. Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. 
Each element must have the same probability of being returned.

题目大意：设计一种数据结构，使得插入，删除和取得随机的数字平均时间是O(1)
解题思路：在常数时间内插入和删除一个数，可以考虑用unordered_map, 但是无法再常数时间内获得一个随机数。
数组可以在常数时间获得随机的一个数。因此使用一个unoreder_map<int, int> umap来记录value，position.这里的
position是在数组中的下标。用vector<int> data记录数据。
对于插入操作，先在umap中查找，如果找到，返回false，在data后面加入，并用umap记录value和pos。
对于删除操作，现在umap中查找，没找到，返回false，如果找到，这里要在O(1)的时间在数组中删除一个元素，
因此这个元素必须是最后一个元素。对于要删除的val，和vector中最后一个元素交换，然后再umap中的pos也交换，这样可以删除umap中
key为val的元素，以及vector中最后一个元素。
对于得到一个随机的数：直接返回vector中的随机的一个数既可，umap中并无影响。
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

class RandomizedSet {

private:
	//存放 value, position
	unordered_map<int, int> umap;
	//存放 value的数组
	vector<int> data;

public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(NULL);
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (umap.find(val) == umap.end())
		{
			data.push_back(val);
			umap.insert({val, data.size() - 1});
			return true;
		}

		return false;

	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (umap.find(val) == umap.end())
			return false;
		else
		{
			//先和最后一个元素交换，保证o(1)的时间在data里面删除一个元素
			int last = data.back();
			umap[last] = umap[val];
			data[umap[val]] = last;

			data.pop_back();
			umap.erase(val);
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		return data[rand() % data.size()];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/


void test()
{
	RandomizedSet r;
	cout << r.insert(1) << endl;
	cout << r.remove(2) << endl;
	cout << r.insert(2) << endl;
	cout << r.getRandom() << endl;
	cout << r.remove(1) << endl;
	cout << r.insert(2) << endl;
	cout << r.getRandom() << endl;

}

int main()
{
	test();

	return 0;
}