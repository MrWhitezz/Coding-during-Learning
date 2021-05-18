#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
void dfs(ll a[], ll h[]);
void dfs_1(ll a[], ll h[], int i);
int n;
int main()
{
    cin >> n;
    ll a[n + 1], h[n + 1];
    h[1] = 1;
    for (int i = 2; i <= n; ++i) {cin >> a[i]; h[i] = 0;}
    dfs(a, h);
    ll ans = 1;
    for (int i = 2; i <= n; ++i)
        ans = (ans + get_reverse(h[i])) % MOD;
    cout << ans;
    return 0;
}
void dfs(ll a[], ll h[]){
    for (int i = 2; i <= n; ++i){
        dfs_1(a, h, i);
    }
}
void dfs_1(ll a[], ll h[], int i){
    if (h[i]) return;
    else {
        dfs_1(a, h, a[i]);
        h[i] = h[a[i]] + 1;
        return;
    }
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