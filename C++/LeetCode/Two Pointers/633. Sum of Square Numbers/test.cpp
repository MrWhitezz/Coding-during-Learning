#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(unsigned c) {
        unsigned l = 0, r = sqrt(c);
        while (l != r + 1){
            if (l * l + r * r == c) return true;
            else if (l * l + r * r < c) ++l;
            else --r;
        }
        return false;
    }
};