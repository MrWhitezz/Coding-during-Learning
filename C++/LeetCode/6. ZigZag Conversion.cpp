// very easy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        if (numRows == 2)
        {
            string res;
            for (int i = 0; i < s.size(); i += 2)
                res.push_back(s[i]);
            for (int i = 1; i < s.size(); i += 2)
                res.push_back(s[i]);
            return res;
        }
        int T = 2 * numRows - 2;
        string res;
        for (int i = 0; i < s.size(); i += T)
            res.push_back(s[i]);
        for (int i = 1; i < numRows - 1; i++)
        {
            for (int j = i; j < s.size(); j += T)
            {
                res.push_back(s[j]);
                if (j + T - 2 * i < s.size())
                    res.push_back(s[j + T - 2 * i]);
            }
        }
        for (int i = numRows - 1; i < s.size(); i += T)
            res.push_back(s[i]);
        return res;
    }
};