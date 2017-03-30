/*
leetcode 274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h 
if h of his/her N papers have at least h citations each, and the other N − h papers 
have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], 
which means the researcher has 5 papers in total and each of them
had received 3, 0, 6, 1, 5 citations respectively. 
Since the researcher has 3 papers with at least 3 citations each and 
the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one 
is taken as the h-index.

题目大意：在发表的n篇文章中，有n篇文字至少被引用h次，其他(n-h)片引用不超过h
解题思路：先由大到小排序，那么对于第i篇文字，h-index = min(i, xitations[i])
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		
		sort(citations.begin(), citations.end());
		int len = citations.size();
		for (size_t i = 0; i < citations.size(); ++i)
		{
			if (citations[i] >= len - i)
				return len - i;
		}

		return 0;
	}
};

void test()
{
	vector<int> v{ 3, 0, 6, 1, 5 };
	Solution sol;
	cout << sol.hIndex(v) << endl;
}

int main()
{
	test();

	return 0;
}