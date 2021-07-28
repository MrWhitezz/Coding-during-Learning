#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll n, m, k;
int T;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll get_factorial(ll n);
ll get_power(ll a, ll n);
ll get_comb(ll n, ll m);
int main()
{
    cin >> T;
    while (T--){
        cin >> n >> m >> k;
        if (k == 1 && n == 1)
            cout << m << endl;
        else if (k == 2)
            cout << m * (m - 1) % MOD;
        else if (m == k)
            cout << k % MOD *((get_power(k - 1, n - 1) - (k - 1) * get_power(k - 2, n - 1) % MOD) % MOD) << endl;
        else
            cout << get_comb(m, k) * k % MOD *((get_power(k - 1, n - 1) - (k - 1) * get_power(k - 2, n - 1) % MOD) % MOD) << endl;
    }

   return 0;
}
ll get_power(ll a, ll n){
    if (n == 0) return 1;
    if (n == 1) return a;
    ll m = n / 2;
    ll tmp = get_power(a, m);
    if (n & 1) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}
ll get_comb(ll n, ll m){
   ll f1, f2, f3, r2, r3;
   f1 = get_factorial(n);
   f2 = get_factorial(n - m);
   f3 = get_factorial(m);
   r2 = get_reverse(f2);
   r3 = get_reverse(f3);
   return f1 * r2 % MOD * r3 % MOD;
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
ll get_factorial(ll n){
   ll res = 1;
   for (ll i = 1; i <= n; i++)
      res = (res * i) % MOD;
   return res;
}
ll get_reverse(ll f){
   ll x, y, tmp;
   extended_gcd(MOD, f, x, y);
   x = y;
   x %= MOD;
   x = x < 0 ? x + MOD : x;
   return x;
}