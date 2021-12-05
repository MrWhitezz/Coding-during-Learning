#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll get_factorial(ll n);
ll get_stage(ll k);
ll N;
int main()
{
   cin >> N;
   ll ans[N + 1], num[N + 1];
   ans[N] = num[N] = 0;
   for (ll i = N - 1; i >= 0; --i)
      num[i] = ((N * get_reverse(N - i)) % MOD + num[i + 1]) % MOD;
   for (ll i = N - 1; i >= 0; --i)
      ans[i] = (num[i] * N % MOD * get_reverse(N - i) % MOD + ans[i + 1]) % MOD;

   cout << ans[0];

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