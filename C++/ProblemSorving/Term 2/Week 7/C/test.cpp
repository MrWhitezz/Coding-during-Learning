#include<bits/stdc++.h>
using namespace std;
int len = 0;
void extendPalindrome(string &s, int i, int j)
{
    while (i >= 0 && j <= s.size() && s[i] == s[j]){
        i--;
        j++;
    }
    if (j - i - 1 > len)
        len = j - i - 1;
}

int longestPalindrome(string s) {
    if (s.size() < 2)
        return 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        extendPalindrome(s, i, i + 1);
        extendPalindrome(s, i, i);
    }
    return len;
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
