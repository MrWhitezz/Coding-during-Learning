#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll guess(ll n);
ll tract_1(ll x);
int main(){
    int T;
    cin >> T;
    ll n;
    while (T--){
        cin >> n;
        cout << guess(n) << endl;

    }
}
ll guess(ll n){
    ll res = tract_1(n);
    for (ll i = 1; i <= max(n, 1000000ll); ++i)
        res = min(res, tract_1(i * n));
    return res;
}
ll tract_1(ll x){
    ll res = 0;
    while (x){
        if (x % 2) ++res;
        x /= 2;
    }
    return res;
}