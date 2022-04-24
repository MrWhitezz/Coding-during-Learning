#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define maxn 5000
int n;
ll b;
ll c[maxn];
ll w[maxn];
ll part_c[maxn]; // c[i] + ... + c[n]
ll val = 0;
ll dfs(int k, ll W, ll C);
int main(){
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for (int i = n; i >= 1; --i){
        part_c[i] = part_c[i + 1] + c[i];
    }

    dfs(1, 0, 0);
    printf("The max value is %lld\n", val);
}
ll dfs(int k, ll W, ll C){
    if (k == n) return C;

    if (C + part_c[k] <= val) return val;
    
    ll t = val;
    if (W + w[k] <= b){
        t = max(val, dfs(k + 1, W + w[k], C + c[k]));
        val = max(val, t); 
    }

    t = max(val, dfs(k + 1, W, C));
    
    val = max(t, val);
    return val;
}