//This is not easy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll n, m, k;
pair<ll, ll> obs;
vector<decltype(obs)> obss;
ll fir[20];
bool cmp(const pair<ll, ll> &pr1, const pair<ll, ll> &pr2);
ll extended_gcd(ll a, ll b, ll &x, ll &y);
ll get_reverse(ll f);
ll get_factorial(ll n);
ll get_comb(ll n, ll m);
ll walk(ll i, ll j);
int main()
{
    cin >> n >> m >> k;
    ll x, y;
    for (int i = 0; i < k; ++i){
        cin >> x >> y;
        obss.push_back({x, y});
    }
    obss.push_back({n, m});
    sort(obss.begin(), obss.end(), cmp);
    for (int i = 0; i < obss.size(); ++i){
        fir[i] = walk(obss[i].first, obss[i].second);
        for (int j = 0; j < i; ++j){
            fir[i] -= (fir[j] *  walk(obss[i].first - obss[j].first, 
            obss[i].second - obss[j].second)) % MOD;
            fir[i] = fir[i] < 0 ? fir[i] % MOD + MOD : fir[i] % MOD;
        }
    }
    cout << fir[obss.size() - 1];

    return 0;
}
bool cmp(const pair<ll, ll> &pr1, const pair<ll, ll> &pr2){
    if (pr1.first == pr2.first) return pr1.second < pr2.second;
    return pr1.first < pr2.first;
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
ll walk(ll i, ll j){
    if (i < 0 || j < 0) return 0;
    return get_comb(i + j, j);
}