// this dp is not very easy, copied from others.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct interval 
{
    ll l, r, c;
}t[2005];

bool operator < (interval a, interval b){
    return a.r < b.r;
}

ll n, m;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> t[i].l >> t[i].r >> t[i].c;
    }
    sort(t + 1, t + 1 + n);
    ll f[n + 5];
    t[n + 1].r = m; t[n + 1].l = m; t[n + 1].c = 1e15;
    for (int i = 1; i <= n + 1; ++i){
        f[i] = t[i].l * t[i].c;
        if (i == n + 1) f[i] = 1e18;
        for (int j = 1; j < i; ++j){
            ll dis = t[i].l - t[j].r;
            if (i != n + 1) f[i] = min(f[i], dis > 0 ? dis * t[i].c + f[j] : f[j]);
            f[i] = min(f[i], dis > 0 ? dis * t[j].c + f[j] : f[j]);
        }
    }
    cout << f[n + 1];
    return 0;
}