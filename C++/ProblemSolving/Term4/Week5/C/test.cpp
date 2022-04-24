#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
#define maxa ((1 << 20))
#define MASK ((1 << 20)  - 1)
#define lim  20
int a[maxn];
ll cnt[maxa];
int n;
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    // very interesting dp, imagin cnt[j][i] is use j as base, free i bits, fixed rest.
    for (int i = 0; i < lim; ++i){
        for (int j = 0; j < maxa; ++j){
            if ((j >> i) & 1){
                cnt[j] += cnt[j ^ (1 << i)];
            }
        }
    }

    for (int i = 0; i < n; ++i)
        ans += cnt[(~a[i]) & MASK];
    
    cout << ans << endl;
    
}