#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int ArSize = 2e6 + 1;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
void get_factorial();
ll get_reverse(ll f);
ll factorial[ArSize];
void get_comb(ll n, ll m);
int main()
{
    get_factorial();
   ll n, m;
   int T;
   cin >> T;
   for (int i = 0; i < T; ++i){
       cin >> n >> m;
       get_comb(n + m, m);
   }
   return T;
}
void get_comb(ll n, ll m){
   ll f1, f2, f3, r2, r3;
   f1 = factorial[n];
   f2 = factorial[n - m];
   f3 = factorial[m];
   r2 = get_reverse(f2);
   r3 = get_reverse(f3);
   cout << f1 * r2 % MOD * r3 % MOD << endl;
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
void get_factorial(){
   factorial[0] = factorial[1] = 1;
   for (ll i = 1; i < ArSize; i++)
      factorial[i] = factorial[i - 1] * i % MOD;
}
ll get_reverse(ll f){
   ll x, y, tmp;
   extended_gcd(MOD, f, x, y);
   x = y;
   x %= MOD;
   x = x < 0 ? x + MOD : x;
   return x;
}