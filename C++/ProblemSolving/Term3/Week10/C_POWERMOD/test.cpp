#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll P;
const ll cut = 1e9;
ll slow_mul(ll a, ll b);
ll fast_pow(ll x, ll N);
int main(){
    ll a, b;
    cin >> a >> b >> P;
    cout << fast_pow(a, b);
}
ll slow_mul(ll A, ll B){
    __int128_t a = A;
    __int128_t b = B;
    return a * b % (__int128_t)P;
}
ll fast_pow(ll x, ll N){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = slow_mul(tmp, tmp) % P){ 
        if (N & 1)
            res = slow_mul(res, tmp) % P;
    }
    return res;
}