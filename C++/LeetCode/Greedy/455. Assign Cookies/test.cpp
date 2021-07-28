#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// g for greed factor, s for size of cookie
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0; 
        while (child != g.size() && cookie != s.size()) {
            if (s[cookie++] >= g[child]) child++;
            // child === ans
        }
        return child;
    }
};