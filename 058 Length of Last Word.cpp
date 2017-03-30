/*
leetcode 58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
����һ�仰�ҳ����һ�����ʵĳ���
����˼·������һ�������ı���count���Ӻ����ң�һ���ҵ�һ��Ϊ��ĸ��count+1,
���������ַ�������ĸ����count>0,�Ϳ��������
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    //�ж��Ƿ�Ϊ��ĸ
    bool IsAlpha(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
public:
    int lengthOfLastWord(string s)
    {
        //�Ӻ��濪ʼ
        int i = s.length() - 1;
        int count = 0;
        while (i >= 0)
        {
            if (IsAlpha(s[i]))
            {
               ++count;
               --i;
            }
            else
            {
                if (count)
                    return count;
                --i;
            }
        }
        return count;
    }
};

void TEST()
{
    Solution sol;
    string s1("this is a test!");
    string s2("this is a !");
    string s3("this is!");
    string s4("Hello World");
    cout << sol.lengthOfLastWord(s1) << endl;
    cout << sol.lengthOfLastWord(s2) << endl;
    cout << sol.lengthOfLastWord(s3) << endl;
    cout << sol.lengthOfLastWord(s4) << endl;
}

int main()
{
    TEST();

    return 0;
}
