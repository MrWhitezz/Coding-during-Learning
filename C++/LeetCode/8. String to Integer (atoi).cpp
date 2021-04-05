#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int flag = 1, base = 0, i = 0;
        while (s[i] == ' ')  {i++;}
        if (s[i] == '+' || s[i] == '-'){
            flag = 1 - 2 * (s[i] == '-');
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9'){
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)){
                if (flag == 1) return INT_MAX;
                if (flag == -1) return INT_MIN;
            }
            base = base * 10 + (s[i] - '0');
            i++;
        }
        return flag * base;
    }
};
int main()
{
    Solution s;
    string s1 = "   -42";
    cout << s.myAtoi(s1);
}