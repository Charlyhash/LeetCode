/*
leetcode 299. Bulls and Cows
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates 
how many digits in said guess match your secret number exactly in both 
digit and position (called "bulls") and how many digits match the secret 
number but locate in the wrong position (called "cows"). Your friend will 
use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and 
friend's guess, use A to indicate the bulls and B to indicate the cows. 
In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate 
digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, 
and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, 
and their lengths are always equal.

题目大意：
解题思路：
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0;
		int Cows = 0;
		int len = secret.size();
		vector<int> v1(10, 0);
		vector<int> v2(10, 0);
		for (int i = 0; i < len; ++i)
		{
			if (secret[i] == guess[i])
				++bulls;
			else
			{
				++v1[secret[i] - '0'];
				++v2[guess[i] - '0'];
			}
		}

		for (int i = 0; i < 10; ++i)
			Cows += min(v1[i], v2[i]);

		//cout << bulls << "," << Cows << endl;
		//string ret = IntToString(bulls) + "A" + IntToString(Cows) + "B";
		string ret = to_string(bulls) + "A" + to_string(Cows) + "B";
		
		return ret;
	}

	string getHint1(string secret, string guess) {
		int bulls = 0;
		int cows = 0;
		int len = secret.size();
		vector<int> v(10, 0);
	
		for (int i = 0; i < len; ++i)
		{
			++v[secret[i] - '0'];
			if (i < guess.size() && secret[i] == guess[i])
				++bulls;
		}
		cows -= bulls;
		for (int i = 0; i < guess.size(); ++i)
			if (v[guess[i] - '0']-- > 0)
				++cows;

		//cout << bulls << "," << Cows << endl;
		//string ret = IntToString(bulls) + "A" + IntToString(Cows) + "B";
		string ret = to_string(bulls) + "A" + to_string(cows) + "B";

		return ret;
	}

	string IntToString(int i)
	{
		stringstream s;
		s << i;
		return s.str();
	}
};

void test()
{
	Solution sol;
	cout << sol.getHint1("1807", "7810") << endl;
	cout << sol.getHint1("0", "1") << endl;
}

int main()
{
	test();

	return 0;
}
