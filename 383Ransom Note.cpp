//leetcode 383. Ransom Note
/*
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
//题目大意：给定两个字符串，ransomNote和magizin,判断是否可以从magzin抽取字母
//组成ransomNote
//解题思路：判断ransomNote中的字符是不是在magazine中即可

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> v(26, 0);
        for (auto c : magazine)
            v[c-'a']++;
        for (auto c : ransomNote)
        {
            if (--v[c-'a'] < 0)
                return false;
        }

        return true;
    }
};

void TEST()
{
    string s1 = "lan";
    string s2 = "xiaolan";
    Solution sol;
    cout << sol.canConstruct(s1, s2) << endl;
}

int main()
{
    TEST();

    return 0;
}
