#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int T;  
ll n, c;
ll p, q, m;
const ll E = 1073741827;
void fac();
ll fast_pow(ll x, ll N, ll P){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = ((__int128_t)tmp * tmp) % P){ 
        if (N & 1)
            res = ((__int128_t)res * tmp) % P;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
ll extend_gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0; y = 1;
        return b;
    }
    else{
        ll a1 = b % a;
        ll b1 = a;
        ll q = b / a;
        ll ans = extend_gcd(a1, b1, x, y);
        ll tmp = y;
        y = x;
        x = tmp - q * x;
        return ans;
    }
}
int main(){
    cin >> T;
    while (T--){
        cin >> n >> c;
        fac();
        m = (p - 1) * (q - 1);
        ll D, F;
        ll d = extend_gcd(E, m, D, F);
        while(D < 0) D += m;
        cout << fast_pow(c, D, n) << endl;
    }
}
void fac(){
    ll mid = round(sqrt(n));
    if ((mid & 1) == 0) mid -= 1;
    while(n % mid != 0){
       mid -= 2;
    }
    p = mid;
    q = n / mid;
}