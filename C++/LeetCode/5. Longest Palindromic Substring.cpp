//我的idea居然和最高赞答案一样！
#include<bits/stdc++.h>
using namespace std;
class Solution {
private :
    int low, len = 0;
    void extendPalindrome(string &s, int i, int j)
    {
        while (i >= 0 && j <= s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }

        if (j - i - 1 > len)
        {
            low = i + 1;
            len = j - i - 1;
        }
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            extendPalindrome(s, i, i + 1);
            extendPalindrome(s, i, i);
        }
        string res(s, low, len);
        return res;
    }
};
int main()
{
    string s = "babad";
    Solution s1;
    cout << s1.longestPalindrome(s);
}