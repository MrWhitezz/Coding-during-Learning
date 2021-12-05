#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll rec(ll &fir, ll& sec, ll times);
ll a, b, c;
int main()
{
   cin >> a >> b >> c;
   ll pos_a = 0, tmp = 1;
   rec(pos_a, tmp, a);
   ll pos_apb = pos_a;
   rec(pos_apb, tmp, b);
   ll x = get_reverse(pos_apb);
   ll res = x * pos_a % MOD;
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
ll rec(ll &fir, ll& sec, ll times)
{
   for (ll i = 0; i < times; ++i){
      ll temp = sec;
      sec = (c * sec % MOD - (c - 1) * fir % MOD) % MOD;
      fir = temp;
   }
   return 0;
}