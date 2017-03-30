/*leetcode345 ---- ��ת�ַ����е�Ԫ����
�ⷨ1���տ�ʼ��������ķ�����ֱ��ȥ�Ƚ�s�е�ÿһ���ַ���Ԫ���Ƿ�һ�������һ���Ļ��ж�Ϊ
Ԫ����Ȼ������ǰ�������±꣬�����ΪԪ���ַ��򽻻���
�ⷨ2���õ���set������ͨ����set������ң�Ч�ʸ�(��Ȼ���￴����Ч������Ϊ��10��Ԫ��)
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int len = s.length();
		if (len == 0 || len == 1)
			return s;
		int i = 0;
		int j = len - 1;
		char c;
		while (i < j)
		{
			while (i < len-1 && !IsVowels(s[i]))
				++i;
			while (j > 0 && !IsVowels(s[j]))
				--j;
			if (j < i || i >len - 1 || j < 0)
				return s;
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			++i;
			--j;
		}
		return s;
	}

private:
	bool IsVowels(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			return true;
		return false;
	}
};

class Solution1
{
public:
	string reverseVowels(string s)
	{
		int len = s.length();
		if (len == 0 || len == 1)
			return s;
		set<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		
		int low = 0;
		int high = len - 1;
		while (low < high)
		{
			while (low < len && v.count(s[low]) == 0)
				low++;
			while (high >= 0 && v.count(s[high]) == 0)
				high--;
			if (low < high)
			{
				swap(s[low], s[high]);
				low++;
				high--;
			}
		}

		return s;
	}
};


int main()
{
	//string s = "leetcode";
	string s{ "a.b,."};
	Solution1 sol;
	cout << sol.reverseVowels(s) << endl;

	return 0;
}