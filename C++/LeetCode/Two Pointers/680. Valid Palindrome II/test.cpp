#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int l, int r){
    while (l < r){
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r){
            if (s[l++] != s[r--]) return isPalindrome(s, l - 1, r) || isPalindrome(s, l, r + 1);
        }
        return true;
    }
};