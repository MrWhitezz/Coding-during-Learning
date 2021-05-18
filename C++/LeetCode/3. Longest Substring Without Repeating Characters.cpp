#include<bits/stdc++.h>
using namespace std;
class my_Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, I = 0, J = 0, i, j;
        for (i = 0; i < s.size(); i++)
        {
            set<char> ch;
            for (j = i; j < s.size(); j++)
            {
                if (ch.find(s[j]) == ch.end())
                    ch.insert(s[j]);
                else
                    break;
            }
            if (j - i > J - I)
            {
                I = i;
                J = j;
            }
        }
        return J - I;
    }
};//this is by myself

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j_start = 0, j = 0, res = 0;
        for (i = 0; i < s.size(); i++)
        {
            for (j = j_start; j < i; j++)
            {
                if (s[j] == s[i])
                {
                    j_start = j + 1;
                }
            }
            res = max(res, i - j_start + 1);
        }
        return res;
    }
};//看的一种以尾为i的遍历方法，每次保证头j_start到以遍历的i无重复元素，非常妙