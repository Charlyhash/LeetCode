#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>

using namespace std;

const int MAXN = 0x7fffffff; //int的最大值
const int MINN = -MAXN - 1;

void PrintVect(vector<int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

void PrintVectVect(vector<vector<int>> v)
{
	for (auto vect : v)
		PrintVect(vect);
}

#endif