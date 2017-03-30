/*
leetcode 380. Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. 
Each element must have the same probability of being returned.

��Ŀ���⣺���һ�����ݽṹ��ʹ�ò��룬ɾ����ȡ�����������ƽ��ʱ����O(1)
����˼·���ڳ���ʱ���ڲ����ɾ��һ���������Կ�����unordered_map, �����޷��ٳ���ʱ���ڻ��һ���������
��������ڳ���ʱ���������һ���������ʹ��һ��unoreder_map<int, int> umap����¼value��position.�����
position���������е��±ꡣ��vector<int> data��¼���ݡ�
���ڲ������������umap�в��ң�����ҵ�������false����data������룬����umap��¼value��pos��
����ɾ������������umap�в��ң�û�ҵ�������false������ҵ�������Ҫ��O(1)��ʱ����������ɾ��һ��Ԫ�أ�
������Ԫ�ر��������һ��Ԫ�ء�����Ҫɾ����val����vector�����һ��Ԫ�ؽ�����Ȼ����umap�е�posҲ��������������ɾ��umap��
keyΪval��Ԫ�أ��Լ�vector�����һ��Ԫ�ء�
���ڵõ�һ�����������ֱ�ӷ���vector�е������һ�����ȿɣ�umap�в���Ӱ�졣
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

class RandomizedSet {

private:
	//��� value, position
	unordered_map<int, int> umap;
	//��� value������
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
			//�Ⱥ����һ��Ԫ�ؽ�������֤o(1)��ʱ����data����ɾ��һ��Ԫ��
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