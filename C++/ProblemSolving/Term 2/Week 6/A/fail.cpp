#include<bits/stdc++.h>
using namespace std;
int base, mod, k;
int main()
{
    cin >> base >> mod >> k;
    vector<int> num;
    auto it = back_inserter(num);
    while (k != 0){
        *it = k % base;
        k /= base;
    }
    if(num.empty()) {cout << "a"; return 0;}
    if (base <= 26){
        for (auto jt = num.crbegin(); jt != num.crend(); ++jt)
            cout << (char)('a' + *jt);
    }
    else{
        // fail
        // Then reach out to Du Xingyu
    }
    return 0;
}