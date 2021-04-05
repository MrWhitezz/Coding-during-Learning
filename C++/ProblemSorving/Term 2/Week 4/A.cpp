#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll diff (ll n);
ll fstPow(ll a, ll n);
ll a, b, c;
int main()
{
    cin >> a >> b >> c;
    ll pos_a, pos_apb;
    if (c != 2){
    pos_a = diff(a);
    pos_apb = diff(a + b);
    }
    else{
        pos_a = a;
        pos_apb = a + b;
    }

    ll res = get_reverse(pos_apb) * pos_a % MOD;
    cout << res;
    return 0;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y){
   ll r, temp;
   if (b == 0) {x = 1; y = 0; return a;}
   r = extended_gcd(b, a % b, x, y);
   temp = x;
   x = y;
   y = temp - a / b * y;
   return r;
}
ll get_reverse(ll f){
   ll x, y, tmp;
   extended_gcd(MOD, f, x, y);
   x = y;
   x %= MOD;
   x = x < 0 ? x + MOD : x;
   return x;
}
ll diff (ll n){
    return get_reverse(c - 2) * (fstPow(c - 1, n) - 1) % MOD;
}
ll fstPow(ll a, ll n){
    if (n == 1) return a;
    ll tmp = fstPow(a, n / 2);
    if (n % 2) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}