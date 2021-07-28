#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(unsigned long long x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        unsigned long long l = 0, r = x, med;
        while (l < r){
            med = (l + r) / 2;
            if (med * med <= x) l = med + 1;
            else r = med; 
        }
        return r - 1;
    }
};