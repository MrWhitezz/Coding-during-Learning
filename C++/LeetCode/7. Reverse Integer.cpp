#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x)
        {
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
int main()
{
    int x = -2147483641;
    Solution s;
    cout << s.reverse(x);
}