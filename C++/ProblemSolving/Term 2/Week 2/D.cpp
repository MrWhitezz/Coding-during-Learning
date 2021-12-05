#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e6 + 3;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll get_factorial(ll n);
ll get_comb(ll n, ll m);
int main()
{
   ll n, m;
   cin >> n >> m;
   ll N[3], M[3];
   for (int i = 0; i < 3; i++){
      N[i] = n % MOD;
      M[i] = m % MOD;
      n /= MOD;
      m /= MOD;
   }

   ll res = 1;
   for (int i = 0; i < 3; i++){
      res = (res * get_comb(N[i], M[i])) % MOD;
   }
   cout << res;
   return n;
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
ll get_comb(ll n, ll m){
   if (n == 0 && m == 0) return 1;
   if (n < m) return 0;
   ll f1, f2, f3, r2, r3;

   f1 = get_factorial(n);
   f2 = get_factorial(n - m);
   f3 = get_factorial(m);

   r2 = get_reverse(f2);
   r3 = get_reverse(f3);

   return f1 * r2 % MOD * r3 % MOD;
}